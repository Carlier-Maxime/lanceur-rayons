#include "Sphere.h"
#include <cmath>
Sphere::Sphere(const Point& center, double radius) {
    this->center = new Point(center);
    this->radius = radius;
}

Sphere::~Sphere() {
    delete center;
}

Point* Sphere::intersect(const Point* o, const Vector* d) const {
    auto* tmp = o->sub(center);
    auto* tmp2 = tmp->mul(2);
    delete tmp;
    double b = tmp2->dot(d);
    delete tmp2;
    tmp = o->sub(center);
    double c = (tmp->dot(tmp))-(radius*radius);
    delete tmp;
    double delta=(b*b)-(4*c);
    double t;
    if(delta<0){
        return nullptr;
    }
    if(delta==0){
        t=(-b)/(2);
    }
    if(delta>0){
        t=(-b+ sqrt(delta))/(2);
        double t2=(-b-sqrt(delta))/(2);
        if(t2>0){
            t=t2;
        }
        else if(t<0){
            return nullptr;

        }
    }
    tmp = d->mul(t);
    Point* p= dynamic_cast<Point*>(o->add(tmp));
    delete tmp;
    return p;
}


Object3D* Sphere::clone() const {
    return new Sphere(*center,radius);
}

Vector *Sphere::getNormal(const Point* p) const {
    auto* pcc = p->sub(center);
    auto* n = dynamic_cast<Vector *>(pcc->hat());
    delete pcc;
    return n;
}
