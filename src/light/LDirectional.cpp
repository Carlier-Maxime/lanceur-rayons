#include "LDirectional.h"

LDirectional::LDirectional(const Color &color, const Vector& direction) : Light(color), direction(direction) {}

Vector LDirectional::getLDir(const Point &p) const {
    return direction.hat();
}

LDirectional::~LDirectional() = default;

Light *LDirectional::clone() const {
    return new LDirectional(getColor(), direction);
}
