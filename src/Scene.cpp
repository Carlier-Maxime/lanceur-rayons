#include "Scene.h"
#include "Exceptions.h"

Scene::Scene(unsigned int width, unsigned int height) : width(width), height(height), nbLight(0), maxLight(0), nbObjects(0), maxObjects(0), outputPath("output.png"), ambient(nullptr), camera(nullptr), objects(nullptr) {}

Scene::~Scene() {
    for (unsigned long long i=0; i<nbObjects; i++) {
        delete objects[i];
    }
    free(objects);
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

void Scene::addLight() {
    nbLight++;
}

void Scene::addObject(const Object3D* o) {
    if (nbObjects>=maxObjects) {
        Object3D** tmp = static_cast<Object3D**>(realloc(objects,maxObjects+128));
        if (!tmp) throw SceneException("Allocation failed !");
        objects = tmp;
        maxObjects+=128;
    }
    objects[nbObjects] = o->clone();
    nbObjects++;
}

unsigned int Scene::getNbLight() const {
    return nbLight;
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
