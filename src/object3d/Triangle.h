#ifndef LANCEUR_RAYONS_TRIANGLE_H
#define LANCEUR_RAYONS_TRIANGLE_H

#include "Object3D.h"

class Triangle : public Object3D {
private:
    Point *a, *b, *c;
public:
    Triangle(Point *a, Point *b, Point *c);
    ~Triangle() override;
    Point* intersect(const Point &o, const Vector &d) const override;
    Vector getNormal(const Point &p) const override;
};

#endif //LANCEUR_RAYONS_TRIANGLE_H