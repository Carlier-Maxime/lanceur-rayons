#include "Scene.h"
#include "../Exceptions.h"
#include <cmath>
#include <thread>

#define INC_NB_OBJS 128
#define INC_NB_LIGHTS 32

Scene::Scene(unsigned int width, unsigned int height) : width(width), height(height), nbLights(0), maxLights(0),
nbObjects(0), maxObjects(0), nbVertices(0), maxVertices(0), outputPath("output.png"), ambient(0.,0,0),
camera(nullptr), objects(nullptr), lights(nullptr), vertices(nullptr), shadow(false), maxDepth(1) {}

Scene::~Scene() {
    for (unsigned long long i=0; i<nbObjects; i++) {
        delete objects[i];
    }
    free(objects);
    for (unsigned int i=0; i<nbLights; i++) {
        delete lights[i];
    }
    free(lights);
    for (unsigned i=0; i<nbVertices; i++) {
        delete vertices[i];
    }
    free(vertices);
    delete camera;
}

void Scene::setOutputPath(std::string path) {
    outputPath = std::move(path);
}

unsigned int Scene::getWidth() const {
    return width;
}

unsigned int Scene::getHeight() const {
    return height;
}

const std::string &Scene::getOutputPath() const {
    return outputPath;
}

void Scene::addLight(const Light *light) {
    if (nbLights>=maxLights) {
        auto** tmp = static_cast<Light**>(realloc(lights,maxLights+INC_NB_LIGHTS));
        if (!tmp) throw SceneException("Allocation failed !");
        lights = tmp;
        maxLights+=INC_NB_LIGHTS;
    }
    lights[nbLights] = light->clone();
    nbLights++;
}

void Scene::addObject(Object3D* o) {
    if (nbObjects>=maxObjects) {
        auto** tmp = static_cast<Object3D**>(realloc(objects,maxObjects+INC_NB_OBJS));
        if (!tmp) throw SceneException("Allocation failed !");
        objects = tmp;
        maxObjects+=INC_NB_OBJS;
    }
    objects[nbObjects] = o;
    nbObjects++;
}

unsigned int Scene::getNbLight() const {
    return nbLights;
}

unsigned long long int Scene::getNbObjects() const {
    return nbObjects;
}

void Scene::setAmbient(const Color& color) {
    this->ambient = color;
}

Color Scene::getAmbient() const {
    return ambient;
}

bool Scene::isShadow(const Point &p, const Vector &lDir) const {
    if (shadow) {
        for (unsigned long long k=0; k<nbObjects; k++) {
            Point* p2 = objects[k]->intersect(p, lDir);
            if(p2 && p2->sub(p).len()>0.001){
                delete p2;
                return true;
            }
        }
    }
    return false;
}

Color Scene::indirectLightning(const Object3D *o, const Vector &d, const Point &p, unsigned char depth) const {
    if (o->getSpecular()==Color(0.,0,0) || depth>=maxDepth) return {0., 0, 0};
    Vector n = o->getNormal(p);
    Vector r = d.add(n.mul(n.dot(d.mul(-1))*2)).hat();
    Object3D* o2 = nullptr;
    Point *p2 = nullptr;
    for (unsigned long long k=0; k<nbObjects; k++) {
        Point* tmp = objects[k]->intersect(p, r);
        if(tmp && tmp->sub(p).len()>0.001 && (!p2 || (p.sub(*tmp).len() < p.sub(*p2).len()))){
            delete p2;
            p2=tmp;
            o2=objects[k];
        } else delete tmp;
    }
    if (p2) {
        Color clr = o->getSpecular().times(getColor(o2,r,*p2,depth+1));
        delete p2;
        return clr;
    }
    return {0.,0,0};
}

Color Scene::getColor(const Object3D *o, const Vector &d, const Point &p, unsigned char depth) const {
    Vector n = o->getNormal(p);
    Color sum = Color(0.,0.,0.);
    for (unsigned int i=0; i<nbLights; i++) {
        Vector lDir = lights[i]->getLDir(p);
        Color adds = indirectLightning(o,d,p,depth);
        Color lClr = lights[i]->getColor();
        if (!isShadow(p,lDir)) {
            double x = n.dot(lDir);
            if (x<0) x=0;
            adds = adds.add(lClr.mul(x).times(o->getDiffuse()));
            double y = n.dot(lDir.add(d.mul(-1)).hat());
            if (y<0) y=0;
            else y=pow(y,o->getShininess());
            adds = adds.add(lClr.mul(y).times(o->getSpecular()));
        }
        sum = sum.add(adds);
    }
    return ambient.add(sum);
}

void Scene::upMaxVertices(unsigned long long int max) {
    if (max<nbVertices) throw SceneException("too many vertices ! (max<nbVertices)");
    auto *tmp = realloc(vertices,sizeof(Point*)*max);
    if (!tmp) throw SceneException("Allocation failed !");
    vertices = static_cast<Point **>(tmp);
    maxVertices = max;
}

void Scene::addVertex(const Point &v) {
    if (nbVertices>=maxVertices) upMaxVertices(maxVertices+256);
    vertices[nbVertices++] = new Point(v);
}

Point *Scene::getVertex(const unsigned long long int i) {
    return vertices[i];
}

void Scene::setCamera(const Camera& newCamera) {
    this->camera = new Camera(newCamera);
}

double* Scene::getDimPixel(){
    double pHeight = tan((camera->getFov()/2));
    double pWidth = pHeight*((width*1.0)/height);
    return new double[2] {pWidth, pHeight};
}
Vector Scene::getVectorD(double maxX, double maxY, unsigned int x, unsigned int y) const {
    double a = (maxX*(x - (width / 2.) + 0.5)) / (width / 2.);
    double b = (maxY*(y - (height / 2.) + 0.5)) / (height / 2.);
    auto* uvw = camera->getOrthonormal();
    Vector d = (uvw[0].mul(a)).add((uvw[1].mul(b))).sub(uvw[2]).hat();
    return d;
}

void Scene::pixelProcessing(Image* img, double* pixDim, unsigned int i, unsigned int j) const {
    img->setColorPixel(i,j,{0.,0.,0.});
    Point *p = nullptr;
    Object3D *object = nullptr;
    Vector d = {0,0,0};
    if (i==330 && j==height-459) {
        img->setPath("");
    }
    for (unsigned long long k=0; k<nbObjects; k++) {
        Point from = camera->getFrom();
        d = getVectorD(pixDim[0], pixDim[1], i, j);
        Point* tmp = objects[k]->intersect(from, d);
        if(tmp && (!p || (from.sub(*tmp).len() < from.sub(*p).len()))){
            delete p;
            p=tmp;
            object=objects[k];
        } else delete tmp;
    }
    if (p) {
        Color clr = getColor(object, d, *p, 1);
        if (clr.getR()>1) clr.setR(1.);
        if (clr.getG()>1) clr.setG(1.);
        if (clr.getB()>1) clr.setB(1.);
        img->setColorPixel(i,j, clr);
        delete p;
    }
}

void Scene::rayTrace(Image* img, double* pixDim, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    for(unsigned int i=x;i<x+width;i++){
        for (unsigned int j=y; j<y+height; j++) {
            pixelProcessing(img,pixDim,i,j);
        }
    }
}

void Scene::exportPNG() {
    auto* img = new Image(width,height);
    auto* pixDim = getDimPixel();
    unsigned int nbThread = std::thread::hardware_concurrency();
    auto* ts = new std::thread[nbThread];
    for (unsigned int i=0; i<nbThread; i++) {
        ts[i] = std::thread(&Scene::rayTrace,this,img,pixDim,0,i*(height/nbThread),width,height/nbThread);
    }
    for (unsigned int i=0; i<nbThread; i++) {
        ts[i].join();
    }
    delete[] ts;
    delete[] pixDim;
    img->setPath(outputPath);
    img->save();
    delete img;
}

void Scene::setShadow(bool shadow) {
    Scene::shadow = shadow;
}

void Scene::setMaxDepth(unsigned char maxDepth) {
    Scene::maxDepth = maxDepth;
}
