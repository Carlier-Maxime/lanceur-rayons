#ifndef LANCEUR_RAYONS_LPOINT_H
#define LANCEUR_RAYONS_LPOINT_H

#include "Light.h"

class LPoint : public Light {
private:
    Point* origin;
public:
    LPoint(const Color &color, const Point& origin);
    ~LPoint();
    Vector *getLDir(const Point *p) const override;
};

#endif //LANCEUR_RAYONS_LPOINT_H
