#include "Point.h"

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

Point::~Point() = default;
