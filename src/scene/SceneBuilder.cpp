#include "SceneBuilder.h"

#include <utility>
#include "../object3d/Sphere.h"
#include "../object3d/Triangle.h"
#include "../object3d/Plane.h"
#include "../Exceptions.h"
#include "../light/LPoint.h"
#include "../light/LDirectional.h"

SceneBuilder::SceneBuilder(unsigned int width, unsigned int height) : _diffuse(0.,0,0), _specular(0.,0,0), _shininess(0) {
    scene = new Scene(width,height);
}

Scene *SceneBuilder::build() {
    return scene;
}

SceneBuilder* SceneBuilder::output(std::string outputPath) {
    scene->setOutputPath(std::move(outputPath));
    return this;
}

SceneBuilder* SceneBuilder::camera(const Point& from, const Point& at, const Vector& up, double fov) {
    scene->setCamera(Camera(from, at, up, fov));
    return this;
}

SceneBuilder* SceneBuilder::ambient(const Color& color) {
    scene->setAmbient(color);
    return this;
}

SceneBuilder* SceneBuilder::diffuse(const Color& color) {
    Color c = Color(scene->getAmbient().add(color));
    bool badColor = c.getR()>1 || c.getG()>1 || c.getB()>1;
    if (badColor) throw BuilderException("exceed 1 on one of the components RGB.");
    _diffuse = color;
    return this;
}

SceneBuilder* SceneBuilder::specular(const Color& color) {
    _specular = color;
    return this;
}

SceneBuilder* SceneBuilder::shininess(unsigned int i) {
    this->_shininess = i;
    return this;
}

SceneBuilder* SceneBuilder::directional(const Vector& direction, const Color& rgb) {
    auto *l = new LDirectional(rgb, direction);
    scene->addLight(l);
    delete l;
    return this;
}

SceneBuilder* SceneBuilder::point(const Point& pos, const Color& color) {
    auto *l = new LPoint(color, pos);
    scene->addLight(l);
    delete l;
    return this;
}

SceneBuilder* SceneBuilder::maxverts(unsigned int max) {
    scene->upMaxVertices(max);
    return this;
}

SceneBuilder* SceneBuilder::vertex(const Point& pos) {
    scene->addVertex(pos);
    return this;
}

SceneBuilder* SceneBuilder::tri(unsigned int iv1, unsigned int iv2, unsigned int iv3) {
    return addObject(new Triangle(scene->getVertex(iv1), scene->getVertex(iv2), scene->getVertex(iv3)));
}

SceneBuilder* SceneBuilder::sphere(const Point& center, double radius) {
    return addObject(new Sphere(center, radius));
}

SceneBuilder* SceneBuilder::plane(const Point& pos, const Vector& normal) {
    return addObject(new Plane(pos,normal));
}

SceneBuilder* SceneBuilder::addObject(Object3D* object) {
    object->setDiffuse(_diffuse);
    object->setSpecular(_specular);
    object->setShininess(_shininess);
    scene->addObject(object);
    return this;
}

SceneBuilder::~SceneBuilder() = default;
