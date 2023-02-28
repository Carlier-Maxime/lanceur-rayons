#include "Sphere.h"

Sphere::Sphere(const Point& center, double radius) {
    this->center = new Point(center);
    this->radius = radius;
}

Sphere::~Sphere() {
    delete center;
}

Point* Sphere::intersect(Vector* d) const {
    return nullptr; // TODO
}

Object3D* Sphere::clone() const {
    return new Sphere(*center,radius);
}