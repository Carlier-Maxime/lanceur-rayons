#include "SceneBuilder.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Plane.h"
#include "Exceptions.h"
#include "LPoint.h"
#include "LDirectional.h"

SceneBuilder::SceneBuilder(unsigned int width, unsigned int height) : _diffuse(nullptr), _specular(nullptr), _shininess(0) {
    scene = new Scene(width,height);
}

Scene *SceneBuilder::build() {
    return scene;
}

SceneBuilder SceneBuilder::output(const std::string& outputPath) {
    scene->setOutputPath(outputPath);
    return *this;
}

SceneBuilder
SceneBuilder::camera(const Point& from, const Point& at, const Vector& up, double fov) {
    scene->setCamera(Camera(from, at, up, fov));
    return *this;
}

SceneBuilder SceneBuilder::ambient(const Color& color) {
    scene->setAmbient(color);
    return *this;
}

SceneBuilder SceneBuilder::diffuse(const Color& color) {
    auto* d = new Color(color);
    auto *c = dynamic_cast<Color*>(scene->getAmbient()->add(d));
    bool badColor = c->getR()>1 || c->getG()>1 || c->getB()>1;
    delete c;
    if (badColor) throw BuilderException("exceed 1 on one of the components RGB.");
    delete _diffuse;
    _diffuse = d;
    return *this;
}

SceneBuilder SceneBuilder::specular(const Color& color) {
    this->_specular = new Color(color);
    return *this;
}

SceneBuilder SceneBuilder::shininess(unsigned int i) {
    this->_shininess = i;
    return *this;
}

SceneBuilder SceneBuilder::directional(const Vector& direction, const Color& rgb) {
    auto *l = new LDirectional(rgb, direction);
    scene->addLight(l);
    delete l;
}

SceneBuilder SceneBuilder::point(const Point& pos, const Color& color) {
    auto *l = new LPoint(color, pos);
    scene->addLight(l);
    delete l;
    return *this;
}

SceneBuilder SceneBuilder::maxverts(unsigned int max) {
    return *this;
}

SceneBuilder SceneBuilder::vertex(const Point& pos) {
    return *this;
}

SceneBuilder SceneBuilder::tri(unsigned int iv1, unsigned int iv2, unsigned int iv3) {
    return addObject(new Triangle());
}

SceneBuilder SceneBuilder::sphere(const Point& center, double radius) {
    return addObject(new Sphere(center, radius));
}

SceneBuilder SceneBuilder::plane(const Point& pos, const Vector& normal) {
    return addObject(new Plane());
}

SceneBuilder SceneBuilder::addObject(Object3D* object) {
    object->setDiffuse(*_diffuse);
    object->setSpecular(*_specular);
    object->setShininess(_shininess);
    scene->addObject(object);
    delete object;
    return *this;
}
