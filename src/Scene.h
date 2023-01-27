#ifndef LANCEUR_RAYONS_SCENE_H
#define LANCEUR_RAYONS_SCENE_H

#include <string>

class Scene {
private:
    unsigned int width, height;
    std::string outputPath;
public:
    Scene(unsigned int width, unsigned int height);
    void setOutputPath(std::string path);

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const std::string &getOutputPath() const;
};

#endif //LANCEUR_RAYONS_SCENE_H
