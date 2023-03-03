#ifndef LANCEUR_RAYONS_TRIANGLE_H
#define LANCEUR_RAYONS_TRIANGLE_H

#include "Object3D.h"

class Triangle : public Object3D {
public:
    Triangle();
    ~Triangle() override;
    Point *intersect(const Point *o, const Vector *d) const override;
    Object3D* clone() const override;

    Vector *getNormal(const Point *p) const override;
};

#endif //LANCEUR_RAYONS_TRIANGLE_H