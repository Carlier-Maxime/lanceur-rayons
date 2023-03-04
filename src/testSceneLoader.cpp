#include <iostream>
#include "SceneLoader.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Argument missing !" << std::endl;
        return EXIT_FAILURE;
    }
    std::string file = argv[1];
    auto* sl = new SceneLoader(file);
    auto* builder = sl->getBuilder();
    Scene* scene = builder->build();
    std::cout << scene->getOutputPath() << std::endl;
    std::cout << scene->getWidth() * scene->getHeight() << std::endl;
    std::cout << scene->getNbObjects() << std::endl;
    std::cout << scene->getNbLight() << std::endl;
    delete scene;
    delete builder;
    delete sl;
    return EXIT_SUCCESS;
}
