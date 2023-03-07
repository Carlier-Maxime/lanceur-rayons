#ifndef LANCEUR_RAYONS_SCENEBUILDER_H
#define LANCEUR_RAYONS_SCENEBUILDER_H

#include <string>
#include "Scene.h"
#include "../triplet/Point.h"
#include "../triplet/Vector.h"
#include "../triplet/Color.h"

class SceneBuilder {
private:
    Scene* scene;
    Color _diffuse;
    Color _specular;
    unsigned int _shininess;
    SceneBuilder* addObject(Object3D* object);
public:
    SceneBuilder(unsigned int width, unsigned int height);
    ~SceneBuilder();
    SceneBuilder* output(std::string outputPath);
    SceneBuilder* camera(const Point& from, const Point& at, const Vector& up, double fov);
    SceneBuilder* ambient(const Color& color);
    SceneBuilder* diffuse(const Color& color);
    SceneBuilder* specular(const Color& color);
    SceneBuilder* shininess(unsigned int i);
    SceneBuilder* directional(const Vector& direction, const Color& color);
    SceneBuilder* point(const Point& pos, const Color& color);
    SceneBuilder* maxverts(unsigned int max);
    SceneBuilder* vertex(const Point& pos);
    SceneBuilder* tri(unsigned iv1, unsigned iv2, unsigned iv3);
    SceneBuilder* sphere(const Point& center, double radius);
    SceneBuilder* plane(const Point& pos, const Vector& normal);
    SceneBuilder* shadow(bool shadow);
    SceneBuilder* maxDepth(unsigned char maxDepth);
    Scene* build();
};

#endif //LANCEUR_RAYONS_SCENEBUILDER_H
