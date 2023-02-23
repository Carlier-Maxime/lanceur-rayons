#ifndef LANCEUR_RAYONS_VECTOR_H
#define LANCEUR_RAYONS_VECTOR_H


#include "Triplet.h"

class Vector : public Triplet {
public:
    Vector(double u, double v, double w);
    unsigned char type() const override;
};


#endif //LANCEUR_RAYONS_VECTOR_H
