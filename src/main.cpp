#include <iostream>
#include "SceneBuilder.h"

int main (int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Argument missing !" << std::endl;
        return EXIT_FAILURE;
    }
    Scene* scene = SceneBuilder(argv[1]).build();
    return EXIT_SUCCESS;
}