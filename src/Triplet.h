#ifndef LANCEUR_RAYONS_TRIPLET_H
#define LANCEUR_RAYONS_TRIPLET_H


#include <ostream>

class Triplet {
protected:
    double x,y,z;
public:
    Triplet(double x, double y, double z);
    Triplet(const Triplet& t);
    bool operator==(const Triplet& t) const;
    bool operator!=(const Triplet& t) const;
    virtual unsigned char type() const;
    Triplet* add(const Triplet* t) const;
    Triplet* sub(const Triplet* t) const;
    Triplet* mul(double scalar) const;
    double dot(const Triplet* t) const;
    Triplet* cross(const Triplet* t) const;
    Triplet* times(const Triplet* t) const;
    double len() const;
    Triplet* hat() const;

    friend std::ostream &operator<<(std::ostream &os, const Triplet &triplet);
};

#endif //LANCEUR_RAYONS_TRIPLET_H
