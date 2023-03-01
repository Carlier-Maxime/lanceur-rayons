#ifndef LANCEUR_RAYONS_OBJECT3D_H
#define LANCEUR_RAYONS_OBJECT3D_H

#include "Point.h"
#include "Vector.h"
#include "Color.h"

class Object3D {
private:
    Color *diffuse;
    Color *specular;
    unsigned int shininess;
public:
    Object3D();
    virtual ~Object3D() {};
    virtual Point* intersect(Vector* d) const = 0;
    virtual Object3D* clone() const = 0;
    void setDiffuse(const Color& color);
    void setSpecular(const Color& color);
    void setShininess(unsigned int i);
};

#endif //LANCEUR_RAYONS_OBJECT3D_H