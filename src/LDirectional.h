#ifndef LANCEUR_RAYONS_LDIRECTIONAL_H
#define LANCEUR_RAYONS_LDIRECTIONAL_H

#include "Light.h"

class LDirectional : public Light {
public:
    LDirectional(const Color &color, const Vector& direction);

    Vector *getLDir(const Point *p) const override;

private:
    Vector* direction;
};

#endif //LANCEUR_RAYONS_LDIRECTIONAL_H
