#include "Triangle.h"
#include "Plane.h"

Triangle::Triangle(Point *a, Point *b, Point *c) : a(a), b(b), c(c) {}

Triangle::~Triangle() = default;

Point * Triangle::intersect(const Point *o, const Vector *d) const {
    auto *n = getNormal(nullptr);
    auto *plane = new Plane(*a,*n);
    auto *p = plane->intersect(o,d);
    if (!p) return nullptr;
    delete plane;
    Triplet *t1, *t2, *t3;
    double r;
    Point* xs[3] = {b,c,a};
    Point* ys[3] = {a,b,c};
    for (unsigned char i=0; i<3; i++) {
        Point *x=xs[i], *y=ys[i];
        t1 = x->sub(y);
        t2 = p->sub(y);
        t3 = t1->cross(t2);
        r = t3->dot(n);
        delete t1;
        delete t2;
        delete t3;
        if (r<0) return nullptr;
    }
    return p;
}

Object3D* Triangle::clone() const {
    return new Triangle(nullptr, nullptr, nullptr);
}

Vector *Triangle::getNormal(const Point *p) const {
    auto* t1 = b->sub(a);
    auto *t2 = c->sub(a);
    auto *t3 = t1->cross(t2);
    auto *n = t3->hat();
    delete t1;
    delete t2;
    delete t3;
    return dynamic_cast<Vector *>(n);
}
