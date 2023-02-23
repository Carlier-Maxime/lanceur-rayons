#ifndef LANCEUR_RAYONS_VECTOR_H
#define LANCEUR_RAYONS_VECTOR_H


#include "Triplet.h"

class Vector : public Triplet {
public:
    Vector(double u, double v, double w);

    explicit Vector(const Triplet &t);

    unsigned char type() const override;
    ~Vector();

    Triplet *sub(const Triplet *t) const override;

    Triplet *cross(const Triplet *t) const override;

    Triplet *add(const Triplet *t) const override;

    Triplet *mul(double scalar) const override;
};


#endif //LANCEUR_RAYONS_VECTOR_H
