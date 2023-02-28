#ifndef LANCEUR_RAYONS_SCENE_H
#define LANCEUR_RAYONS_SCENE_H

#include <string>
#include "Color.h"
#include "Camera.h"

class Scene {
private:
    unsigned int width, height, nbLight;
    unsigned long long nbObjects;
    std::string outputPath;
    Color *ambient;
    Camera *camera;
public:
    Scene(unsigned int width, unsigned int height);
    void setOutputPath(std::string path);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const std::string &getOutputPath() const;
    void addLight();
    void addObject();
    unsigned int getNbLight() const;
    unsigned long long int getNbObjects() const;
    void setAmbient(const Color& ambient);
    void setCamera(const Camera& camera);
};

#endif //LANCEUR_RAYONS_SCENE_H
