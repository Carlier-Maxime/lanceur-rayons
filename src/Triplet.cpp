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
Triplet add(const Triplet& t1,const Triplet& t2){
    Triplet t3 = Triplet(t1->x+t2->x,t1->y+t2->y,t1->z+t2->z);
    return t3;
}
Triplet sub(const Triplet& t1,const Triplet& t2){
    Triplet t3 = Triplet(t1->x-t2->x,t1->y-t2->y,t1->z-t2->z);
    return t3;
}
Triplet mul(const Triplet& t1,double scal){
    Triplet t3 = Triplet(t1->x*scal,t1->y*scal,t1->z*scal);
    return t3;
}
double dot(const Triplet& t1,const Triplet& t2){
    double prod= t1->x*t2->x+t1->y*t2->y+t1->z*t2->z;
    return prod;
}

Triplet cross(const Triplet& t1, const Triplet& t2){
      Triplet t3 = Triplet((t1->y*t2->z)-(t1->z*t2->y),(t1->z*t2->x)-(t1->x*t2->z),(t1->x*t2->y)-(t1->y*t2->x));
      return t3;
}
Triplet times(const Triplet& t1, const Triplet& t2){
       Triplet t3 = Triplet(t1->x*t2->x,t1->y*t2->y,t1->z*t2->z);
      return t3;
}
double len(const Triplet& t1){
    double taille= sqrt(t1.x*t1.x+t1.y*t1.y+t1.z*t1.z);
      return taille;
}

Triplet hat(const Triplet& t1){
    Triplet t3 = mul(t1,(1/len(t1)));
      return t3;
}



