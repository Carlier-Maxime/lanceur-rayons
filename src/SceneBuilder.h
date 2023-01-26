#ifndef LANCEUR_RAYONS_SCENEBUILDER_H
#define LANCEUR_RAYONS_SCENEBUILDER_H

#include <string>
#include "Scene.h"

class SceneBuilder {
private:
    Scene* scene;
    void size(std::istream& is);
    void output(std::istream& is);
    void camera(std::istream& is);
    void ambient(std::istream& is);
    void diffuse(std::istream& is);
    void specular(std::istream& is);
    void shininess(std::istream& is);
    void directional(std::istream& is);
    void point(std::istream& is);
    void maxverts(std::istream& is);
    void vertex(std::istream& is);
    void tri(std::istream& is);
    void sphere(std::istream& is);
    void plane(std::istream& is);
public:
    explicit SceneBuilder(const std::string& filepath);
    SceneBuilder size(unsigned int width, unsigned int height);
    SceneBuilder output(const std::string& outputPath);
    SceneBuilder camera(double x, double y, double z, double u, double v, double w, double n, double o, double f);
    SceneBuilder ambient(double r, double g, double b);
    SceneBuilder diffuse(double r, double g, double b);
    SceneBuilder specular(double r, double g, double b);
    SceneBuilder shininess(unsigned int i);
    SceneBuilder directional(double x, double y, double z, double r, double g, double b);
    SceneBuilder point(double x, double y, double z, double r, double g, double b);
    SceneBuilder maxverts(unsigned max);
    SceneBuilder vertex(double x, double y, double z);
    SceneBuilder tri(unsigned iv1, unsigned iv2, unsigned iv3);
    SceneBuilder sphere(double x, double y, double z, double r);
    SceneBuilder plane(double x, double y, double z, double u, double v, double w);
    Scene* build();
};

#endif //LANCEUR_RAYONS_SCENEBUILDER_H
