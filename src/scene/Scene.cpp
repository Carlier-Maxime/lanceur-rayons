#include "Scene.h"
#include "../Exceptions.h"
#include "../light/Light.h"
#include "../Image.h"
#include <cmath>


#define INC_NB_OBJS 128
#define INC_NB_LIGHTS 32

Scene::Scene(unsigned int width, unsigned int height) : width(width), height(height), nbLights(0), maxLights(0),
nbObjects(0), maxObjects(0), nbVertices(0), maxVertices(0), outputPath("output.png"), ambient(0.,0,0),
camera(nullptr), objects(nullptr), lights(nullptr), vertices(nullptr) {}

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

Color Scene::getColor(const Object3D *o, const Point& p) const {
    Vector n = o->getNormal(p);
    Color sum = Color(0.,0.,0.);
    for (unsigned int i=0; i<nbLights; i++) {
        double x = n.dot(lights[i]->getLDir(p));
        if (x<0) x=0;
        sum = Color(sum.add(lights[i]->getColor().mul(x)));
    }
    return Color(ambient.add(sum.times(o->getDiffuse())));
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
Vector Scene::getVectorD(double maxX, double maxY, unsigned int x, unsigned int y) {
    double a = (maxX*(x - (width / 2.) + 0.5)) / (width / 2.);
    double b = (maxY*(y - (height / 2.) + 0.5)) / (height / 2.);
    auto* uvw = camera->getOrthonormal();
    Vector d = (uvw[0].mul(a)).add((uvw[1].mul(b))).sub(uvw[2]).hat();
    return d;
}

void Scene::pixelProcessing(Image* img, double* pixDim, unsigned int i, unsigned int j) {
    img->setColorPixel(i,j,{0.,0.,0.});
    Point *p = nullptr;
    Object3D *object = nullptr;
    for (unsigned long long k=0; k<nbObjects; k++) {
        Point from = camera->getFrom();
        Vector d = getVectorD(pixDim[0], pixDim[1], i, j);
        Point* tmp = objects[k]->intersect(from, d);
        if(tmp && (!p || (from.sub(*tmp).len() < from.sub(*p).len()))){
            delete p;
            p=tmp;
            object=objects[k];
        }
    }
    if (p) {
        img->setColorPixel(i,j, getColor(object,*p));
        delete p;
    }
}

void Scene::exportPNG() {
    auto* img = new Image(width,height);
    auto* pixDim = getDimPixel();
    for(unsigned int i=0;i<width;i++){
        for (unsigned int j=0; j<height; j++) {
            pixelProcessing(img,pixDim,i,j);
        }
    }
    delete[] pixDim;
    img->setPath(outputPath);
    img->save();
    delete img;
}
