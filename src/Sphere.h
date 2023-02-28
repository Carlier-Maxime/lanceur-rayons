#ifndef LANCEUR_RAYONS_SPHERE_H
#define LANCEUR_RAYONS_SPHERE_H

#include "Object3D.h"

class Sphere : public Object3D {
private:
    Point* center;
    double radius;
public:
    Sphere(const Point& center, double radius);
    ~Sphere() override;
    Point* intersect(Vector* d) override;
    Object3D* clone() const override;
};

#endif //LANCEUR_RAYONS_SPHERE_H