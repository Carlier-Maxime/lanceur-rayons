#include "Vector.h"
#include "Point.h"

Vector::Vector(double u, double v, double w) : Triplet(u, v, w) {}

unsigned char Vector::type() const {
    return 'V';
}

Vector::Vector(const Triplet &t) : Triplet(t) {}

Triplet *Vector::add(const Triplet *t) const {
    Triplet* tr=Triplet::add(t);
    if (t->type()=='P') {
        auto* p = new Point(*tr);
        delete tr;
        return p;
    } else if (t->type()=='V') {
        auto* v = new Vector(*tr);
        delete tr;
        return v;
    }
    return tr;
}

Triplet *Vector::sub(const Triplet *t) const {
    Triplet* tr=Triplet::sub(t);
    if (t->type()=='V') {
        auto* v = new Vector(*tr);
        delete tr;
        return v;
    }
    return tr;
}

Triplet *Vector::mul(double scalar) const {
    Triplet* tr=Triplet::mul(scalar);
    auto* v = new Vector(*tr);
    delete tr;
    return v;
}

Triplet *Vector::cross(const Triplet *t) const {
    Triplet* tr=Triplet::cross(t);
    if (t->type()=='V') {
        auto* v = new Vector(*tr);
        delete tr;
        return v;
    }
    return tr;
}

Vector::~Vector() = default;
