#include "Point.h"
#include "Vector.h"

Point::Point(double x, double y, double z) : Triplet(x, y, z) {}

unsigned char Point::type() const {
    return 'P';
}

Point::Point(const Triplet &t) : Triplet(t) {}

Triplet *Point::add(const Triplet *t) const {
    if (t->type()=='V') return new Point(add(*t));
    return Triplet::add(t);
}

Point Point::add(const Vector &v) const {
    return Point(Triplet::add(v));
}

Triplet *Point::sub(const Triplet *t) const {
    if (t->type()=='P') return new Vector(sub(*t));
    return Triplet::sub(t);
}

Vector Point::sub(const Point &p) const {
    return Vector(Triplet::sub(p));
}

Triplet *Point::mul_ptr(double scalar) const {
    return new Point(baseMul(scalar));
}

Point::~Point() = default;
