#include "LPoint.h"

LPoint::LPoint(const Color &color, const Point& origin) : Light(color), origin(origin) {}

Vector LPoint::getLDir(const Point &p) const {
    return origin.sub(p).hat();
}

LPoint::~LPoint() = default;

Light *LPoint::clone() const {
    return new LPoint(getColor(), origin);
}
