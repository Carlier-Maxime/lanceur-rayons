#ifndef LANCEUR_RAYONS_SCENE_H
#define LANCEUR_RAYONS_SCENE_H

#include <string>
#include "Color.h"
#include "Camera.h"
#include "Object3D.h"

class Scene {
private:
    unsigned int width, height, nbLight, maxLight;
    unsigned long long nbObjects, maxObjects;
    std::string outputPath;
    Color *ambient;
    Camera *camera;
    Object3D **objects;
public:
    Scene(unsigned int width, unsigned int height);
    ~Scene();
    void setOutputPath(std::string path);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const std::string &getOutputPath() const;
    void addLight();
    void addObject(const Object3D* o);
    unsigned int getNbLight() const;
    unsigned long long int getNbObjects() const;
    void setAmbient(const Color& ambient);
    void setCamera(const Camera& camera);
};

#endif //LANCEUR_RAYONS_SCENE_H
