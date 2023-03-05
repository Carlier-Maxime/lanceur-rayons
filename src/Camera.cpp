#include "Camera.h"
#include <cmath>

Camera::Camera(const Point& from, const Point& at, const Vector& up, double fov) : from(from), at(at), up(up), fov(fov), uvw(nullptr) {}

Camera::~Camera() {
    delete[] uvw;
}

const Vector* Camera::getOrthonormal() {
    if (uvw) return uvw;
    Vector w = from.sub(at).hat();
    Vector u = up.cross(w).hat();
    Vector v = w.cross(u).hat();
    uvw = new Vector[3] {u,v,w};
    return uvw;
}

double Camera::getFov() const {
    return (fov*M_PI)/180;
}

Point Camera::getFrom() const {
    return from;
}

Camera::Camera(const Camera& camera) : Camera(camera.from,camera.at,camera.up,camera.fov) {}