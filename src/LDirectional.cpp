#include "LDirectional.h"

LDirectional::LDirectional(const Color &color, const Vector& direction) : Light(color), direction(new Vector(direction)) {}

Vector *LDirectional::getLDir(const Point *p) const {
    return dynamic_cast<Vector *>(direction->hat());
}
