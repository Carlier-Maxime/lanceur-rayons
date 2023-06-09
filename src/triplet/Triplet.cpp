#include <cmath>
#include <sstream>
#include <iomanip>
#include "Triplet.h"

Triplet::Triplet(double x, double y, double z) : x(x), y(y), z(z) {}

bool Triplet::operator==(const Triplet& t) const {
    return x==t.x && y==t.y && z==t.z;
}

bool Triplet::operator!=(const Triplet& t) const {
    return !(operator==(t));
}

unsigned char Triplet::type() const {
    return 'T';
}

Triplet *Triplet::add(const Triplet *t) const {
    if (!t) return nullptr;
    return new Triplet(add(*t));
}

Triplet Triplet::add(const Triplet &t) const {
    return {x+t.x,y+t.y,z+t.z};
}

Triplet *Triplet::sub(const Triplet *t) const {
    if (!t) return nullptr;
    return new Triplet(sub(*t));
}

Triplet Triplet::sub(const Triplet& t) const {
    return {x-t.x,y-t.y,z-t.z};
}

Triplet *Triplet::mul_ptr(double scalar) const {
    return new Triplet(baseMul(scalar));
}

Triplet Triplet::baseMul(double scalar) const {
    return {x*scalar,y*scalar,z*scalar};
}

double Triplet::dot(const Triplet *t) const {
    if (!t) return -1;
    return x*t->x+y*t->y+z*t->z;
}

double Triplet::dot(const Triplet &t) const {
    return dot(&t);
}

Triplet *Triplet::cross(const Triplet *t) const {
    if (!t) return nullptr;
    return new Triplet(cross(*t));
}

Triplet Triplet::cross(const Triplet &t) const {
    return {(y*t.z)-(z*t.y),(z*t.x)-(x*t.z),(x*t.y)-(y*t.x)};
}

Triplet *Triplet::times(const Triplet *t) const {
    if (!t) return nullptr;
    return new Triplet(times(*t));
}

Triplet Triplet::times(const Triplet &t) const {
    return {x*t.x,y*t.y,z*t.z};
}

double Triplet::len() const {
    return sqrt(x*x+y*y+z*z);
}

Triplet *Triplet::hat_ptr() const {
    return mul_ptr(1 / len());
}

Triplet Triplet::baseHat() const {
    return baseMul(1 / len());
}

std::ostream &operator<<(std::ostream &os, const Triplet &triplet) {
    os << triplet.type() << " " << triplet.x << " " << triplet.y << " " << triplet.z;
    return os;
}

Triplet::Triplet(const Triplet &t) : Triplet(t.x, t.y, t.z) {}

std::string Triplet::toString() const {
    std::stringstream ss;
    ss << type() << " " << x << ((int) x == x ? ".0 " : " ") << y << ((int) y == y ? ".0 " : " ") << z << ((int) z == z ? ".0" : "");
    return ss.str();
}

Triplet::~Triplet() = default;
