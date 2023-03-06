#ifndef LANCEUR_RAYONS_SPHERE_H
#define LANCEUR_RAYONS_SPHERE_H

#include "Object3D.h"

class Sphere : public Object3D {
private:
    Point center;
    double radius;
public:
    Sphere(const Point& center, double radius);
    Point* intersect(const Point &o, const Vector &d) const override;
    Vector getNormal(const Point &p) const override;
};

#endif //LANCEUR_RAYONS_SPHERE_H