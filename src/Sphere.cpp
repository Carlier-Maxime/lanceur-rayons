#include "Sphere.h"

Sphere::Sphere(const Point& center, double radius) {
    this->center = new Point(center);
    this->radius = radius;
}

Sphere::~Sphere() {
    delete center;
}

Point * Sphere::intersect(const Point *o, const Vector *d) const {
    return nullptr; // TODO
}

Object3D* Sphere::clone() const {
    return new Sphere(*center,radius);
}

Vector *Sphere::getNormal(const Point* p) const {
    auto* pcc = p->sub(center);
    auto* n = dynamic_cast<Vector *>(pcc->hat());
    delete pcc;
    return n;
}
