#include "Triangle.h"

Triangle::Triangle() = default;

Triangle::~Triangle() {

}

Point * Triangle::intersect(const Point *o, const Vector *d) const {
    return nullptr; // TODO
}

Object3D* Triangle::clone() const {
    return new Triangle();
}

Vector *Triangle::getNormal(const Point *p) const {
    return nullptr; // TODO
}
