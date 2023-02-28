#ifndef LANCEUR_RAYONS_OBJECT3D_H
#define LANCEUR_RAYONS_OBJECT3D_H

#include "Point.h"
#include "Vector.h"

class Object3D {
public:
    virtual ~Object3D();
    virtual Point* intersect(Vector* d);
};

#endif //LANCEUR_RAYONS_OBJECT3D_H