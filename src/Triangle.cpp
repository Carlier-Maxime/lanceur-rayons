#include "Triangle.h"

Triangle::Triangle() = default;

Triangle::~Triangle() {

}

Point* Triangle::intersect(Vector* d) const {
    return nullptr; // TODO
}

Object3D* Triangle::clone() const {
    return new Triangle();
}