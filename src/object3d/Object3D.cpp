#include "Object3D.h"

Object3D::Object3D() : diffuse(0.,0,0), specular(0.,0,0), shininess(0) {}

void Object3D::setDiffuse(const Color &color) {
    this->diffuse = color;
}

void Object3D::setSpecular(const Color &color) {
    this->specular = color;
}

void Object3D::setShininess(unsigned int i) {
    this->shininess = i;
}

Color Object3D::getDiffuse() const {
    return diffuse;
}

Object3D::~Object3D() = default;
