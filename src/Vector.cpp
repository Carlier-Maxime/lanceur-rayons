#include "Vector.h"

Vector::Vector(double u, double v, double w) : Triplet(u, v, w) {}

unsigned char Vector::type() {
    return 'V';
}
