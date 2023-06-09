#ifndef LANCEUR_RAYONS_PLANE_H
#define LANCEUR_RAYONS_PLANE_H

#include "Object3D.h"

class Plane : public Object3D {
private:
    Point pos;
    Vector normal;
public:
    Plane(const Point& pos, const Vector& normal);
    ~Plane() override;
    Point* intersect(const Point &o, const Vector &d) const override;
    Vector getNormal(const Point &p) const override;
};

#endif //LANCEUR_RAYONS_PLANE_H