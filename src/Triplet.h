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
    static Triplet add(const Triplet& t1,const Triplet& t2);
    static Triplet sub(const Triplet& t1,const Triplet& t2);
    static Triplet mul(const Triplet& t1,double scal);
    static double dot(const Triplet& t1,const Triplet& t2);
    static Triplet cross(const Triplet& t1,const Triplet& t2);
    static Triplet times(const Triplet& t1,const Triplet& t2);
    static double len(const Triplet& t1);
    static Triplet hat(const Triplet& t1);

};

#endif //LANCEUR_RAYONS_TRIPLET_H
