#include <fstream>
#include <iostream>
#include "SceneBuilder.h"
#include "Exceptions.h"

SceneBuilder::SceneBuilder(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) throw FileException("Open file failed");
    std::string line;
    while (getline(file,line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

Scene *SceneBuilder::build() {
    return scene;
}
