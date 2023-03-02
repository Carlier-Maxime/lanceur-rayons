#ifndef LANCEUR_RAYONS_SCENE_H
#define LANCEUR_RAYONS_SCENE_H

#include <string>
#include "Color.h"
#include "Camera.h"
#include "Object3D.h"
#include "Light.h"

class Scene {
private:
    unsigned int width, height, nbLights, maxLights;
    unsigned long long nbObjects, maxObjects;
    std::string outputPath;
    Color *ambient;
    Camera *camera;
    Object3D **objects;
    Light **lights;
private:
    Color *getColor(const Object3D* o, const Point* p) const;
public:
    Scene(unsigned int width, unsigned int height);
    ~Scene();
    void setOutputPath(std::string path);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const std::string &getOutputPath() const;
    void addLight(const Light *light);
    void addObject(const Object3D* o);
    unsigned int getNbLight() const;
    unsigned long long int getNbObjects() const;
    void setAmbient(const Color& color);
    void setCamera(const Camera& newCamera);
    Color *getAmbient() const;
};

#endif //LANCEUR_RAYONS_SCENE_H
