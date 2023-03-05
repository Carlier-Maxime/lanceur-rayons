#ifndef LANCEUR_RAYONS_CAMERA_H
#define LANCEUR_RAYONS_CAMERA_H

#include "triplet/Point.h"
#include "triplet/Vector.h"

class Camera {
private:
    Point from;
    Point at;
    Vector up;
    double fov;
    Vector* uvw;
public:
    Camera(const Point& from, const Point& at, const Vector& up, double fov);
    Camera(const Camera& camera);
    ~Camera();
    const Vector* getOrthonormal();
    double getFov() const;
    Point getFrom() const;
};

#endif //LANCEUR_RAYONS_CAMERA_H