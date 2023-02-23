#ifndef LANCEUR_RAYONS_POINT_H
#define LANCEUR_RAYONS_POINT_H


#include "Triplet.h"
#include "Vector.h"

class Point : public Triplet {
public:
    Point(double x, double y, double z);
    explicit Point(const Triplet &t);
    unsigned char type() const override;

    Triplet *add(const Triplet *t) const override;
    ~Point();
};


#endif //LANCEUR_RAYONS_POINT_H
