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
SceneBuilder::camera(Point from, Point at, Vector up, double fov) {
    return *this;
}

SceneBuilder SceneBuilder::ambient(Color color) {
    return *this;
}

SceneBuilder SceneBuilder::diffuse(Color color) {
    return *this;
}

SceneBuilder SceneBuilder::specular(Color color) {
    return *this;
}

SceneBuilder SceneBuilder::shininess(unsigned int i) {
    return *this;
}

SceneBuilder SceneBuilder::directional(Vector direction, Color rgb) {
    return *this;
}

SceneBuilder SceneBuilder::point(Point pos, Color color) {
    return *this;
}

SceneBuilder SceneBuilder::maxverts(unsigned int max) {
    return *this;
}

SceneBuilder SceneBuilder::vertex(Point pos) {
    return *this;
}

SceneBuilder SceneBuilder::tri(unsigned int iv1, unsigned int iv2, unsigned int iv3) {
    return *this;
}

SceneBuilder SceneBuilder::sphere(Point center, double radius) {
    return *this;
}

SceneBuilder SceneBuilder::plane(Point pos, Vector normal) {
    return *this;
}
