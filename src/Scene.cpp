#include "Scene.h"

Scene::Scene(unsigned int width, unsigned int height) : width(width), height(height), nbLight(0), nbObjects(0), outputPath("output.png"), ambient(nullptr), camera(nullptr) {}

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

void Scene::addObject() {
    nbObjects++;
}

unsigned int Scene::getNbLight() const {
    return nbLight;
}

unsigned long long int Scene::getNbObjects() const {
    return nbObjects;
}

void Scene::setAmbient(const Color& ambient) {
    this->ambient = new Color(ambient);
}

void Scene::setCamera(const Camera& camera) {
    this->camera = new Camera(camera);
}