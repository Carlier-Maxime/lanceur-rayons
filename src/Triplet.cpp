#include <math.h>
#include "Triplet.h"

Triplet::Triplet(double x, double y, double z) : x(x), y(y), z(z) {}

bool Triplet::operator==(const Triplet& t) const {
    return x==t.x && y==t.y && z==t.z;
}

bool Triplet::operator!=(const Triplet& t) const {
    return !(operator==(t));
}

Triplet Triplet::add(const Triplet& t1,const Triplet& t2){
    Triplet t3 = Triplet(t1.x+t2.x,t1.y+t2.y,t1.z+t2.z);
    return t3;
}
Triplet Triplet::sub(const Triplet& t1,const Triplet& t2){
    Triplet t3 = Triplet(t1.x-t2.x,t1.y-t2.y,t1.z-t2.z);
    return t3;
}
Triplet Triplet::mul(const Triplet& t1,double scal){
    Triplet t3 = Triplet(t1.x*scal,t1.y*scal,t1.z*scal);
    return t3;
}
double Triplet::dot(const Triplet& t1,const Triplet& t2){
    double prod= t1.x*t2.x+t1.y*t2.y+t1.z*t2.z;
    return prod;
}

Triplet Triplet::cross(const Triplet& t1, const Triplet& t2){
      Triplet t3 = Triplet((t1.y*t2.z)-(t1.z*t2.y),(t1.z*t2.x)-(t1.x*t2.z),(t1.x*t2.y)-(t1.y*t2.x));
      return t3;
}
Triplet Triplet::times(const Triplet& t1, const Triplet& t2){
       Triplet t3 = Triplet(t1.x*t2.x,t1.y*t2.y,t1.z*t2.z);
      return t3;
}
double Triplet::len(const Triplet& t1){
    double taille = sqrt(t1.x*t1.x+t1.y*t1.y+t1.z*t1.z);
    return taille;
}

Triplet Triplet::hat(const Triplet& t1){
    Triplet t3 = mul(t1,(1/len(t1)));
      return t3;
}



