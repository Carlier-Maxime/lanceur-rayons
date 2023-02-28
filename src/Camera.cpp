#include "Camera.h"

Camera::Camera(const Point& from, const Point& at, const Vector& up, double fov) {
    this->from = new Point(from);
    this->at = new Point(at);
    this->up = new Vector(up);
    this->fov = fov;
}

Camera::~Camera() {
    delete from;
    delete at;
    delete up;
}

Vector* Camera::getOrthonormal() {
    return nullptr; // TODO (return [u,v,w])
}

double Camera::getFov() {
    return fov;
}