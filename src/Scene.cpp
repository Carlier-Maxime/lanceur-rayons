#include "Scene.h"
#include "Exceptions.h"
#include "Light.h"
#include "Image.h"
#include <cmath>


#define INC_NB_OBJS 128
#define INC_NB_LIGHTS 32

Scene::Scene(unsigned int width, unsigned int height) : width(width), height(height), nbLights(0), maxLights(0),
nbObjects(0), maxObjects(0), nbVertices(0), maxVertices(0), outputPath("output.png"), ambient(nullptr),
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
    delete ambient;
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

void Scene::addObject(const Object3D* o) {
    if (nbObjects>=maxObjects) {
        auto** tmp = static_cast<Object3D**>(realloc(objects,maxObjects+INC_NB_OBJS));
        if (!tmp) throw SceneException("Allocation failed !");
        objects = tmp;
        maxObjects+=INC_NB_OBJS;
    }
    objects[nbObjects] = o->clone();
    nbObjects++;
}

unsigned int Scene::getNbLight() const {
    return nbLights;
}

unsigned long long int Scene::getNbObjects() const {
    return nbObjects;
}

void Scene::setAmbient(const Color& color) {
    this->ambient = new Color(color);
}

Color *Scene::getAmbient() const {
    return ambient;
}

Color *Scene::getColor(const Object3D *o, const Point *p) const {
    auto *n = o->getNormal(p);
    auto *sum = new Color(0.,0.,0.);
    for (unsigned int i=0; i<nbLights; i++) {
        auto *dir = lights[i]->getLDir(p);
        double x = n->dot(dir);
        if (x<0) x=0;
        auto *t = lights[i]->getColor()->mul_ptr(x);
        auto *t2 = sum;
        sum = dynamic_cast<Color *>(sum->add(t));
        delete t2;
        delete t;
        delete dir;
    }
    delete n;
    auto *tmp = sum->times(o->getDiffuse());
    auto *color = ambient->add(tmp);
    delete tmp;
    return dynamic_cast<Color *>(color);
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
    auto* pixDim = static_cast<double*>(malloc(2 * sizeof(double )));
    pixDim[1]=pHeight;
    pixDim[0]=pWidth;
    return pixDim;
}
Vector * Scene::getVectorD(double maxX, double maxY, unsigned int x, unsigned int y) {
    double a = (maxX*(x - (width / 2.) + 0.5)) / (width / 2.);
    double b = (maxY*(y - (height / 2.) + 0.5)) / (height / 2.);
    auto** uvw = camera->getOrthonormal();
    auto* t1 = uvw[0]->mul_ptr(a);
    auto* t2 = uvw[1]->mul_ptr(b);
    auto* t3 = t1->add(t2);
    auto* numD = t3->sub(uvw[2]);
    delete uvw[0];
    delete uvw[1];
    delete uvw[2];
    free(uvw);
    auto* v = numD->hat_ptr();
    delete numD;
    delete t3;
    delete t2;
    delete t1;
    return dynamic_cast<Vector*>(v);
}

void Scene::exportPNG() {
    auto* img = new Image(width,height);
    auto * pixDim = getDimPixel();
    for(unsigned int i=0;i<width;i++){
        for (unsigned int j=0; j<height; j++) {
            img->setColorPixel(i,j,{0.,0.,0.});
            if (i==170 && j==102) {
                img->setPath("test.png");
            }
            for (unsigned long long k=0; k<nbObjects; k++) {
                auto *d = getVectorD(pixDim[0], pixDim[1], i, j);
                Point* p = objects[k]->intersect(camera->getFrom(), d);
                delete d;
                if(p){
                    img->setColorPixel(i,j,*ambient);
                    delete p;
                    break;
                }
            }
        }
    }
    free(pixDim);
    img->setPath(outputPath);
    img->save();
    delete img;
}
