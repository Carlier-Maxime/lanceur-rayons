#ifndef LANCEUR_RAYONS_SCENELOADER_H
#define LANCEUR_RAYONS_SCENELOADER_H


#include <istream>
#include <sstream>
#include "SceneBuilder.h"

class SceneLoader {
private:
    bool builderIsInit;
    SceneBuilder builder;
    std::stringstream ss;
    void size();
    void output();
    void camera();
    void ambient();
    void diffuse();
    void specular();
    void shininess();
    void directional();
    void point();
    void maxverts();
    void vertex();
    void tri();
    void sphere();
    void plane();
    std::string getWord();
    unsigned int getUint();
    double getDouble();
public:
    explicit SceneLoader(const std::string& filepath);
    SceneBuilder getBuilder();
};


#endif //LANCEUR_RAYONS_SCENELOADER_H
