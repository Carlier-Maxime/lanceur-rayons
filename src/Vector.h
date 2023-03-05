#ifndef LANCEUR_RAYONS_VECTOR_H
#define LANCEUR_RAYONS_VECTOR_H

#include "Triplet.h"
class Point;

class Vector : public Triplet {
public:
    Vector(double u, double v, double w);
    ~Vector() override;
    explicit Vector(const Triplet &t);
    unsigned char type() const override;

    Triplet *sub(const Triplet *t) const override;
    Vector sub(const Vector& v) const;
    using Triplet::sub;
    Triplet *cross(const Triplet *t) const override;
    Vector cross(const Vector& v) const;
    using Triplet::cross;
    Triplet *add(const Triplet *t) const override;
    Point add(const Point &p) const;
    Vector add(const Vector& v) const;
    using Triplet::add;
    Triplet *mul_ptr(double scalar) const override;
    Vector mul(double scalar) const;
    Triplet *hat_ptr() const override;
    Vector hat() const;
};


#endif //LANCEUR_RAYONS_VECTOR_H
