#ifndef LANCEUR_RAYONS_POINT_H
#define LANCEUR_RAYONS_POINT_H

#include "Triplet.h"
#include "Vector.h"

class Point : public Triplet {
public:
    Point(double x, double y, double z);
    ~Point() override;
    explicit Point(const Triplet &t);
    unsigned char type() const override;

    Triplet *add(const Triplet *t) const override;
    Point add(const Vector& v) const;
    using Triplet::add;
    Triplet *mul_ptr(double scalar) const override;
    Triplet *sub(const Triplet *t) const override;
    Vector sub(const Point& p) const;
    using Triplet::sub;
};

#endif //LANCEUR_RAYONS_POINT_H
