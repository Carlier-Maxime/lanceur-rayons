#include "Scene.h"
#include "Exceptions.h"
#include "Light.h"

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

void Scene::setCamera(const Camera& newCamera) {
    this->camera = new Camera(newCamera);
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
        auto *t = lights[i]->getColor()->mul(x);
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
