#include "Plane.h"

Plane::Plane(const Point& pos, const Vector& normal) : pos(new Point(pos)), normal(new Vector(normal)) {}

Plane::~Plane() {
    delete pos;
    delete normal;
}

Point * Plane::intersect(const Point *o, const Vector *d) const {
    double b = d->dot(normal);
    if (b==0) return nullptr;
    auto* tmp = pos->sub(o);
    double a = tmp->dot(normal);
    delete tmp;
    double t = a/b;
    tmp = d->mul_ptr(t);
    auto* p = o->add(tmp);
    delete tmp;
    return dynamic_cast<Point *>(p);
}

Object3D* Plane::clone() const {
    return new Plane(*pos,*normal);
}

Vector *Plane::getNormal(const Point *p) const {
    return normal;
}
