#ifndef LANCEUR_RAYONS_TRIPLET_H
#define LANCEUR_RAYONS_TRIPLET_H


class Triplet {
protected:
    double x,y,z;
public:
    Triplet(double x, double y, double z);
    bool operator==(const Triplet &t) const;
    friend bool operator==(const Triplet* t1, const Triplet& t2);
    friend bool operator==(const Triplet& t1, const Triplet* t2);
    bool operator!=(const Triplet &t) const;
    friend bool operator!=(const Triplet* t1, const Triplet& t2);
    friend bool operator!=(const Triplet& t1, const Triplet* t2);
};

#endif //LANCEUR_RAYONS_TRIPLET_H
