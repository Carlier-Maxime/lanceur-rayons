#ifndef LANCEUR_RAYONS_COLOR_H
#define LANCEUR_RAYONS_COLOR_H

class Color {
private:
    unsigned char r,g,b;
public:
    Color(unsigned char r,unsigned char g, unsigned char b);

    unsigned char getR() const;

    unsigned char getG() const;

    unsigned char getB() const;

    void setR(unsigned char r);

    void setG(unsigned char g);

    void setB(unsigned char b);

    void setRGB(unsigned char red, unsigned char green, unsigned char blue);
};

#endif //LANCEUR_RAYONS_COLOR_H
