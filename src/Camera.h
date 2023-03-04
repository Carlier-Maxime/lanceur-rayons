#ifndef LANCEUR_RAYONS_CAMERA_H
#define LANCEUR_RAYONS_CAMERA_H

#include "Point.h"
#include "Vector.h"

class Camera {
private:
    Point* from;
    Point* at;
    Vector* up;
    double fov;
public:
    Camera(const Point& from, const Point& at, const Vector& up, double fov);
    ~Camera();
    Vector** getOrthonormal();
    double getFov();
};

#endif //LANCEUR_RAYONS_CAMERA_H