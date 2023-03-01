#include "Object3D.h"

Object3D::Object3D() : diffuse(nullptr), specular(nullptr), shininess(0) {}

void Object3D::setDiffuse(const Color &color) {
    this->diffuse = new Color(color);
}

void Object3D::setSpecular(const Color &color) {
    this->specular = new Color(color);
}

void Object3D::setShininess(unsigned int i) {
    this->shininess = i;
}
