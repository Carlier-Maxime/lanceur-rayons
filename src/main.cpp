#include <iostream>
#include "SceneLoader.h"

int main (int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Argument missing !" << std::endl;
        return EXIT_FAILURE;
    }
    SceneLoader(argv[1]).getBuilder().build();
    return EXIT_SUCCESS;
}