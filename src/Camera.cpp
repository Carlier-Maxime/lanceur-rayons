#include "Camera.h"
#include <cmath>

Camera::Camera(const Point& from, const Point& at, const Vector& up, double fov) : from(from), at(at), up(up), fov(fov) {}

Vector* Camera::getOrthonormal() {
    Vector w = from.sub(at).hat();
    Vector u = up.cross(w).hat();
    Vector v = w.cross(u).hat();
    return new Vector[3] {u,v,w};
}

double Camera::getFov() const {
    return (fov*M_PI)/180;
}

Point Camera::getFrom() const {
    return from;
}

Camera::Camera(const Camera& camera) : Camera(camera.from,camera.at,camera.up,camera.fov) {}