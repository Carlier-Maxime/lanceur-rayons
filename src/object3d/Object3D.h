#ifndef LANCEUR_RAYONS_OBJECT3D_H
#define LANCEUR_RAYONS_OBJECT3D_H

#include "../triplet/Point.h"
#include "../triplet/Vector.h"
#include "../triplet/Color.h"

class Object3D {
private:
    Color diffuse;
    Color specular;
    unsigned int shininess;
public:
    Object3D();
    virtual ~Object3D();
    virtual Point* intersect(const Point &o, const Vector &d) const = 0;
    void setDiffuse(const Color& color);
    void setSpecular(const Color& color);
    void setShininess(unsigned int i);
    virtual Vector getNormal(const Point &p) const = 0;
    Color getDiffuse() const;

    const Color &getSpecular() const;

    unsigned int getShininess() const;
};

#endif //LANCEUR_RAYONS_OBJECT3D_H