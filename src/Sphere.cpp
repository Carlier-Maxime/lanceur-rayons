#include "Sphere.h"

Sphere::Sphere(const Point& center, double radius) {
    this->center = new Point(center);
    this->radius = radius;
}

Sphere::~Sphere() {
    delete center;
}

Point* Sphere::intersect(Vector* d) {
    return nullptr; // TODO
}