#ifndef LANCEUR_RAYONS_TRIPLET_H
#define LANCEUR_RAYONS_TRIPLET_H


class Triplet {
protected:
    double x,y,z;
public:
    Triplet(double x, double y, double z);
    bool operator==(const Triplet& t) const;
    bool operator!=(const Triplet& t) const;
    void operator+=(const Triplet& t);
    Triplet operator+(const Triplet& t) const;
    void operator-=(const Triplet& t);
    Triplet operator-(const Triplet& t) const;
    void operator*=(double scalar);
    Triplet operator*(double scalar) const;
    void operator*=(const Triplet& t);
    Triplet operator*(const Triplet& t) const;
    double prodScalar(const Triplet& t) const;
    Triplet prodVector(const Triplet& t) const;
    double len() const;
    Triplet norm() const;

};

#endif //LANCEUR_RAYONS_TRIPLET_H
