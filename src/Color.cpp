#include "Color.h"

double Color::getR() const {
    return x;
}

double Color::getG() const {
    return y;
}

double Color::getB() const {
    return z;
}

unsigned char Color::getR255() const {
    return (unsigned char) (getR()*255);
}

unsigned char Color::getG255() const {
    return (unsigned char) (getG()*255);
}

unsigned char Color::getB255() const {
    return (unsigned char) (getB()*255);
}

Color::Color(double red, double green, double blue) : Triplet(red, green, blue) {}
Color::Color(unsigned char red, unsigned char green, unsigned char blue) : Color((red*1.0)/255,(green*1.0)/255,(blue*1.0)/255) {}

void Color::setR(double red) {
    x=red;
}

void Color::setG(double green) {
    y=green;
}

void Color::setB(double blue) {
    z=blue;
}

void Color::setR(unsigned char red) {
    setR((red*1.0)/255);
}

void Color::setG(unsigned char green) {
    setG((green*1.0)/255);
}

void Color::setB(unsigned char blue) {
    setB((blue*1.0)/255);
}

void Color::setRGB(unsigned char red, unsigned char green, unsigned char blue) {
    setRGB((red*1.0)/255,(green*1.0)/255,(blue*1.0)/255);
}

void Color::setRGB(double red, double green, double blue) {
    x=red;
    y=green;
    z=blue;
}
