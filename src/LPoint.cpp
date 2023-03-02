#include "LPoint.h"

LPoint::LPoint(const Color &color, const Point& origin) : Light(color), origin(new Point(origin)) {}

Vector *LPoint::getLDir(const Point *p) const {
    auto* t = origin->sub(p);
    auto* dir = dynamic_cast<Vector*>(t->hat());
    delete t;
    return dir;
}

LPoint::~LPoint() {
    delete origin;
}
