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
    Point *intersect(const Point *o, const Vector *d) const override;
    Object3D* clone() const override;

    Vector *getNormal(const Point* p) const override;
    void exportPNG();
};

#endif //LANCEUR_RAYONS_SPHERE_H