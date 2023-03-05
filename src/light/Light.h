#ifndef LANCEUR_RAYONS_LIGHT_H
#define LANCEUR_RAYONS_LIGHT_H

#include "../triplet/Color.h"
#include "../triplet/Vector.h"
#include "../triplet/Point.h"

class Light {
private:
    Color color;
public:
    explicit Light(const Color& color);
    virtual ~Light();
    virtual Vector getLDir(const Point &p) const = 0;
    Color getColor() const;
    virtual Light *clone() const = 0;
};

#endif //LANCEUR_RAYONS_LIGHT_H
