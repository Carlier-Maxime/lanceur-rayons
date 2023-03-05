#include "Sphere.h"
#include <cmath>
Sphere::Sphere(const Point& center, double radius) : center(center), radius(radius) {}

Point* Sphere::intersect(const Point &o, const Vector &d) const {
    Vector oc = o.sub(center);
    double b = oc.mul(2).dot(d);
    double c = (oc.dot(oc))-(radius*radius);
    double delta=(b*b)-(4*c);
    double t;
    if(delta<0) return nullptr;
    if(delta==0) t=(-b)/(2);
    if(delta>0){
        t=(-b+ sqrt(delta))/(2);
        double t2=(-b-sqrt(delta))/(2);
        if(t2>0) t=t2;
        else if(t<0) return nullptr;
    }
    return new Point(o.add(d.mul(t)));
}


Object3D* Sphere::clone() const {
    return new Sphere(center,radius);
}

Vector Sphere::getNormal(const Point &p) const {
    return p.sub(center).hat();
}
