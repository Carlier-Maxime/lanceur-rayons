#ifndef LANCEUR_RAYONS_SCENEBUILDER_H
#define LANCEUR_RAYONS_SCENEBUILDER_H

#include <string>
#include "Scene.h"

class SceneBuilder {
private:
    Scene* scene;
public:
    explicit SceneBuilder(const std::string& filepath);
    Scene* build();
};

#endif //LANCEUR_RAYONS_SCENEBUILDER_H
