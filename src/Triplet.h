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
    virtual Triplet* add(const Triplet* t) const;
    Triplet add(const Triplet& t) const;
    virtual Triplet* sub(const Triplet* t) const;
    Triplet sub(const Triplet& t) const;
    virtual Triplet* mul_ptr(double scalar) const;
    Triplet mul(double scalar) const;
    double dot(const Triplet* t) const;
    double dot(const Triplet& t) const;
    virtual Triplet* cross(const Triplet* t) const;
    Triplet cross(const Triplet& t) const;
    virtual Triplet* times(const Triplet* t) const;
    Triplet times(const Triplet& t) const;
    double len() const;
    virtual Triplet* hat_ptr() const;
    Triplet hat() const;

    friend std::ostream &operator<<(std::ostream &os, const Triplet &triplet);
    std::string toString() const;
    virtual ~Triplet();
};

#endif //LANCEUR_RAYONS_TRIPLET_H
