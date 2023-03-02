#include "Point.h"
#include "Vector.h"

Point::Point(double x, double y, double z) : Triplet(x, y, z) {}

unsigned char Point::type() const {
    return 'P';
}

Point::Point(const Triplet &t) : Triplet(t) {}

Triplet *Point::add(const Triplet *t) const {
    Triplet* tr=Triplet::add(t);
    if (t->type()=='V') {
        auto* p = new Point(*tr);
        delete tr;
        return p;
    }
    return tr;
}

Triplet *Point::sub(const Triplet *t) const {
    Triplet* tr=Triplet::sub(t);
    if (t->type()=='P') {
        auto* v = new Vector(*tr);
        delete tr;
        return v;
    }
    return tr;
}

Triplet *Point::mul(double scalar) const {
    Triplet* tr=Triplet::mul(scalar);
    auto* p = new Point(*tr);
    delete tr;
    return p;
}

Point::~Point() = default;
