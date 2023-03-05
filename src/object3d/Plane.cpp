#include "Plane.h"

Plane::Plane(const Point& pos, const Vector& normal) : pos(pos), normal(normal) {}

Plane::~Plane() = default;

Point* Plane::intersect(const Point &o, const Vector &d) const {
    double b = d.dot(normal);
    if (b==0) return nullptr;
    double a = pos.sub(o).dot(normal);
    double t = a/b;
    return new Point(o.add(d.mul(t)));
}

Object3D* Plane::clone() const {
    return new Plane(pos,normal);
}

Vector Plane::getNormal(const Point &p) const {
    return normal;
}
