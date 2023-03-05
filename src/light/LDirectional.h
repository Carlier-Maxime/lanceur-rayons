#ifndef LANCEUR_RAYONS_LDIRECTIONAL_H
#define LANCEUR_RAYONS_LDIRECTIONAL_H

#include "Light.h"

class LDirectional : public Light {
private:
    Vector direction;
public:
    LDirectional(const Color &color, const Vector& direction);
    ~LDirectional() override;
    Vector getLDir(const Point &p) const override;
    Light *clone() const override;
};

#endif //LANCEUR_RAYONS_LDIRECTIONAL_H
