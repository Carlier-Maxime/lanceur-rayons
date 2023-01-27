#ifndef LANCEUR_RAYONS_SCENEBUILDER_H
#define LANCEUR_RAYONS_SCENEBUILDER_H

#include <string>
#include "Scene.h"
#include "Point.h"
#include "Vector.h"
#include "Color.h"

class SceneBuilder {
private:
    Scene* scene;
public:
    SceneBuilder(unsigned int width, unsigned int height);
    SceneBuilder output(const std::string& outputPath);
    SceneBuilder camera(Point from, Point at, Vector up, double fov);
    SceneBuilder ambient(Color color);
    SceneBuilder diffuse(Color color);
    SceneBuilder specular(Color color);
    SceneBuilder shininess(unsigned int i);
    SceneBuilder directional(Vector direction, Color color);
    SceneBuilder point(Point pos, Color color);
    SceneBuilder maxverts(unsigned int max);
    SceneBuilder vertex(Point pos);
    SceneBuilder tri(unsigned iv1, unsigned iv2, unsigned iv3);
    SceneBuilder sphere(Point center, double radius);
    SceneBuilder plane(Point pos, Vector normal);
    Scene* build();
};

#endif //LANCEUR_RAYONS_SCENEBUILDER_H
