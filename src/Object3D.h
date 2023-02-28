#ifndef LANCEUR_RAYONS_OBJECT3D_H
#define LANCEUR_RAYONS_OBJECT3D_H

#include "Point.h"
#include "Vector.h"

class Object3D {
public:
    virtual ~Object3D() {};
    virtual Point* intersect(Vector* d) = 0;
    virtual Object3D* clone() const = 0;
};

#endif //LANCEUR_RAYONS_OBJECT3D_H