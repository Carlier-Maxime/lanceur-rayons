#include <iostream>
#include "SceneLoader.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Argument missing !" << std::endl;
        return EXIT_FAILURE;
    }
    Scene* scene = SceneLoader(argv[1]).getBuilder().build();
    std::cout << scene->getOutputPath() << std::endl;
    std::cout << scene->getWidth() * scene->getHeight() << std::endl;
    std::cout << scene->getNbObjects() << std::endl;
    std::cout << scene->getNbLight() << std::endl;
    delete scene;
    return EXIT_SUCCESS;
}
