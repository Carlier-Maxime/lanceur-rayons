#include <iostream>
#include "SceneLoader.h"
#include "Image.h"

int main (int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Argument missing !" << std::endl;
        return EXIT_FAILURE;
    }
    Image::init();
    Scene *scene = SceneLoader(argv[1]).getBuilder().build();
    scene->exportPNG();
    delete scene;
    Image::free();
    return EXIT_SUCCESS;
}