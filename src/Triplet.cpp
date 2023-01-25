#include "Triplet.h"

Triplet::Triplet(double x, double y, double z) : x(x), y(y), z(z) {}

bool Triplet::operator==(const Triplet &t) const {
    return x==t.x && y==t.y && z==t.z;
}

bool operator==(const Triplet *t1, const Triplet &t2) {
    if (t1 == nullptr) return false;
    return (*t1) == t2;
}

bool operator==(const Triplet &t1, const Triplet *t2) {
    if (t2 == nullptr) return false;
    return (t2 == t1);
}

bool Triplet::operator!=(const Triplet &t) const {
    return !(this == t);
}

bool operator!=(const Triplet *t1, const Triplet &t2) {
    if (t1 == nullptr) return false;
    return (*t1) != t2;
}

bool operator!=(const Triplet &t1, const Triplet *t2) {
    if (t2 == nullptr) return false;
    return t1 != (*t2);
}
