#include "Color.h"

unsigned char Color::getR() const {
    return r;
}

unsigned char Color::getG() const {
    return g;
}

unsigned char Color::getB() const {
    return b;
}

Color::Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}

void Color::setR(unsigned char red) {
    r = red;
}

void Color::setG(unsigned char green) {
    g = green;
}

void Color::setB(unsigned char blue) {
    b = blue;
}

void Color::setRGB(unsigned char red, unsigned char green, unsigned char blue) {
    r = red;
    g = green;
    b = blue;
}
