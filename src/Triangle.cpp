#include "Triangle.h"
#include "Plane.h"

Triangle::Triangle(Point *a, Point *b, Point *c) : a(a), b(b), c(c) {}

Triangle::~Triangle() = default;

Point* Triangle::intersect(const Point &o, const Vector &d) const {
    Vector n = getNormal(o);
    auto *p = Plane(*a,n).intersect(o,d);
    if (!p) return nullptr;
    Point* xs[3] = {b,c,a};
    Point* ys[3] = {a,b,c};
    for (unsigned char i=0; i<3; i++) {
        Point *x=xs[i], *y=ys[i];
        if ((x->sub(*y)).cross(p->sub(*y)).dot(n) < 0) return nullptr;
    }
    return p;
}

Object3D* Triangle::clone() const {
    return new Triangle(new Point(*a), new Point(*b), new Point(*c));
}

Vector Triangle::getNormal(const Point &p) const {
    return (b->sub(*a)).cross(c->sub(*a)).hat();
}
