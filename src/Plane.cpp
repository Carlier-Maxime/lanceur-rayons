#include "Plane.h"

Plane::Plane() = default;

Plane::~Plane() {

}

Point* Plane::intersect(Vector* d) const {
    return nullptr; // TODO
}

Object3D* Plane::clone() const {
    return new Plane();
}