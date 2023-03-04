#ifndef LANCEUR_RAYONS_COLOR_H
#define LANCEUR_RAYONS_COLOR_H

#include "Triplet.h"

class Color : public Triplet {
private:
    static unsigned char to255(double value);
public:
    Color(double red, double green, double blue);
    Color(unsigned char red,unsigned char green, unsigned char blue);

    explicit Color(const Triplet &t);

    unsigned char getR255() const;
    unsigned char getG255() const;
    unsigned char getB255() const;
    double getR() const;
    double getG() const;
    double getB() const;

    void setR(unsigned char red);
    void setR(double red);
    void setG(unsigned char green);
    void setG(double green);
    void setB(unsigned char blue);
    void setB(double blue);

    void setRGB(unsigned char red, unsigned char green, unsigned char blue);
    void setRGB(double red, double green, double blue);

    Color difference(Color clr2) const;

    unsigned char type() const override;
    ~Color();

    Triplet *add(const Triplet *t) const override;

    Triplet *mul(double scalar) const override;

    Triplet *times(const Triplet *t) const override;
};

#endif //LANCEUR_RAYONS_COLOR_H
