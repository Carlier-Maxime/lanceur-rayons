#include <iostream>
#include "Image.h"

int main(int argc, char* argv[]) {
    if (argc<3) {
        std::cerr << "Argument missing !" << std::endl;
        return EXIT_FAILURE;
    }
    Image::init();
    unsigned long long error = (new Image(argv[1]))->compare(new Image(argv[2]));
    std::cout << ((error>1000) ? "KO" : "OK") << std::endl << error << std::endl;
    Image::free();
    return EXIT_SUCCESS;
}