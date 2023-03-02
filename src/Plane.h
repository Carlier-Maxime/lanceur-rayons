#ifndef LANCEUR_RAYONS_PLANE_H
#define LANCEUR_RAYONS_PLANE_H

#include "Object3D.h"

class Plane : public Object3D {
public:
    Plane();
    ~Plane() override;
    Point* intersect(Vector* d) const override;
    Object3D* clone() const override;

    Vector *getNormal(const Point *p) const override;
};

#endif //LANCEUR_RAYONS_PLANE_H