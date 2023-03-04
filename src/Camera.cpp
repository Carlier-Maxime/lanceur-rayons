#include "Camera.h"
#include <cmath>

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

Vector** Camera::getOrthonormal() {
    Triplet* numW= from->sub(at);
    Triplet* w = numW->hat();

    Triplet* numU= up->cross(w);
    Triplet * u=numU->hat();

    Triplet* numV= w->cross(u);
    Triplet* v= numV->hat();
    auto** ortho = static_cast<Vector **>(malloc(3*sizeof(Vector*)));
    ortho[0]= dynamic_cast<Vector *>(u);
    ortho[1]= dynamic_cast<Vector *>(v);
    ortho[2]= dynamic_cast<Vector *>(w);
    delete numW;
    delete numU;
    delete numV;
    return ortho; //
}

double Camera::getFov() {
    double fovr;
    fovr= (this->fov*M_PI)/180;
    return fovr;
}

Point* Camera::getFrom() const {
    return from;
}

Camera::Camera(const Camera& camera) : Camera(*(camera.from),*(camera.at),*(camera.up),camera.fov) {}