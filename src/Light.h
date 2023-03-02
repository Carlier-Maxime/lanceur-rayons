#ifndef LANCEUR_RAYONS_LIGHT_H
#define LANCEUR_RAYONS_LIGHT_H

#include "Color.h"
#include "Vector.h"
#include "Point.h"

class Light {
private:
    Color* color;
public:
    explicit Light(const Color& color);
    ~Light();
    virtual Vector* getLDir(const Point* p) const = 0;

    Color *getColor() const;
};

#endif //LANCEUR_RAYONS_LIGHT_H
