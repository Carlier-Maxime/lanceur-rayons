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
    return to255(getR());
}

unsigned char Color::getG255() const {
    return to255(getG());
}

unsigned char Color::getB255() const {
    return to255(getB());
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

Color Color::difference(Color clr2) const {
    Color clrD = Color(0.,0.,0.);
    if (getR() != clr2.getR() || getG() != clr2.getG() || getB() != clr2.getB()) {
        clrD.setR((getR()>clr2.getR()) ? getR()-clr2.getR() : clr2.getR()-getR());
        clrD.setG((getG()>clr2.getG()) ? getG()-clr2.getG() : clr2.getG()-getG());
        clrD.setB((getB()>clr2.getB()) ? getB()-clr2.getB() : clr2.getB()-getB());
    }
    return clrD;
}

unsigned char Color::type() const {
    return 'C';
}

Color::~Color() = default;

Triplet *Color::add(const Triplet *t) const {
    Triplet* tr=Triplet::add(t);
    if (t->type()=='C') {
        auto* c = new Color(*tr);
        delete tr;
        return c;
    }
    return tr;
}

Color::Color(const Triplet &t) : Triplet(t) {}

Triplet *Color::mul(double scalar) const {
    Triplet* tr=Triplet::mul(scalar);
    auto* c = new Color(*tr);
    delete tr;
    return c;
}

Triplet *Color::times(const Triplet *t) const {
    Triplet* tr=Triplet::times(t);
    if (t->type()=='C') {
        auto* c = new Color(*tr);
        delete tr;
        return c;
    }
    return tr;
}

unsigned char Color::to255(double value) {
    auto n = (unsigned char) (value*255);
    if (((value*255)-n)==0.5) n++;
    return n;
}
