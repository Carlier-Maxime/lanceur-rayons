#include "Point.h"

Point::Point(double x, double y, double z) : Triplet(x, y, z) {}

unsigned char Point::type() {
    return 'P';
}
