#include "Vector.h"
#include "Point.h"

Vector::Vector(double u, double v, double w) : Triplet(u, v, w) {}

unsigned char Vector::type() const {
    return 'V';
}

Vector::Vector(const Triplet &t) : Triplet(t) {}

Triplet *Vector::add(const Triplet *t) const {
    if (t->type()=='P') return new Point(add(*t));
    if (t->type()=='V') return new Vector(add(*t));
    return Triplet::add(t);
}

Point Vector::add(const Point &p) const {
    return Point(Triplet::add(p));
}

Vector Vector::add(const Vector &v) const {
    return Vector(Triplet::add(v));
}

Triplet *Vector::sub(const Triplet *t) const {
    if (t->type()=='V') return new Vector(sub(*t));
    return Triplet::sub(t);
}

Vector Vector::sub(const Vector &v) const {
    return Vector(Triplet::sub(v));
}

Triplet *Vector::mul_ptr(double scalar) const {
    return new Vector(mul(scalar));
}

Triplet *Vector::cross(const Triplet *t) const {
    if (t->type()=='V') return new Vector(cross(*t));
    return Triplet::cross(t);
}

Vector Vector::cross(const Vector &v) const {
    return Vector(Triplet::cross(v));
}

Vector::~Vector() = default;
