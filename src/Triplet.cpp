#include <cmath>
#include "Triplet.h"

Triplet::Triplet(double x, double y, double z) : x(x), y(y), z(z) {}

bool Triplet::operator==(const Triplet& t) const {
    return x==t.x && y==t.y && z==t.z;
}

bool Triplet::operator!=(const Triplet& t) const {
    return !(operator==(t));
}

void Triplet::operator+=(const Triplet &t) {
    x+=t.x;
    y+=t.y;
    z+=t.z;
}

Triplet Triplet::operator+(const Triplet &t) const {
    return {x+t.x,y+t.y,z+t.z};
}

void Triplet::operator-=(const Triplet &t) {
    x-=t.x;
    y-=t.y;
    z-=t.z;
}

Triplet Triplet::operator-(const Triplet &t) const {
    return {x-t.x,y-t.y,z-t.z};
}

void Triplet::operator*=(double scalar) {
    x*=scalar;
    y*=scalar;
    z*=scalar;
}

Triplet Triplet::operator*(double scalar) const {
    return {x*scalar,y*scalar,z*scalar};
}

void Triplet::operator*=(const Triplet &t) {
    x*=t.x;
    y*=t.y;
    z*=t.z;
}

Triplet Triplet::operator*(const Triplet &t) const {
    return {x*t.x,y*t.y,z*t.z};
}

double Triplet::prodScalar(const Triplet &t) const {
    return x*t.x+y*t.y+z*t.z;
}

Triplet Triplet::prodVector(const Triplet &t) const {
    return {(y*t.z)-(z*t.y),(z*t.x)-(x*t.z),(x*t.y)-(y*t.x)};
}

double Triplet::len() const{
    return sqrt(x*x+y*y+z*z);
}

Triplet Triplet::norm() const{
    return operator*(1/len());
}

unsigned char Triplet::type() const {
    return 'T';
}

std::ostream &operator<<(std::ostream &os, const Triplet &triplet) {
    os << triplet.type() << " " << triplet.x << " " << triplet.y << " " << triplet.z;
    return os;
}
