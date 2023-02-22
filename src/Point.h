#ifndef LANCEUR_RAYONS_POINT_H
#define LANCEUR_RAYONS_POINT_H


#include "Triplet.h"

class Point : public Triplet {
public:
    Point(double x, double y, double z);
    unsigned char type() override;
};


#endif //LANCEUR_RAYONS_POINT_H
