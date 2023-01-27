#include "SceneBuilder.h"

SceneBuilder::SceneBuilder(unsigned int width, unsigned int height) {
    scene = new Scene(width,height);
}

Scene *SceneBuilder::build() {
    return scene;
}

SceneBuilder SceneBuilder::output(const std::string& outputPath) {
    scene->setOutputPath(outputPath);
    return *this;
}

SceneBuilder
SceneBuilder::camera(double x, double y, double z, double u, double v, double w, double m, double n, double o, double f) {
    return *this;
}

SceneBuilder SceneBuilder::ambient(double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::diffuse(double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::specular(double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::shininess(unsigned int i) {
    return *this;
}

SceneBuilder SceneBuilder::directional(double x, double y, double z, double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::point(double x, double y, double z, double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::maxverts(unsigned int max) {
    return *this;
}

SceneBuilder SceneBuilder::vertex(double x, double y, double z) {
    return *this;
}

SceneBuilder SceneBuilder::tri(unsigned int iv1, unsigned int iv2, unsigned int iv3) {
    return *this;
}

SceneBuilder SceneBuilder::sphere(double x, double y, double z, double r) {
    return *this;
}

SceneBuilder SceneBuilder::plane(double x, double y, double z, double u, double v, double w) {
    return *this;
}
