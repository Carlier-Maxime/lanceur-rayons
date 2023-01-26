#include <iostream>
#include "Image.h"

int main(int argc, char* argv[]) {
    if (argc<3) {
        std::cerr << "Argument missing !" << std::endl;
        return EXIT_FAILURE;
    }
    Image::init();
    auto *img1 = new Image(argv[1]);
    auto *img2 = new Image(argv[2]);
    unsigned long long error = (img1)->compare(img2);
    std::cout << ((error>1000) ? "KO" : "OK") << std::endl << error << std::endl;
    delete img2;
    delete img1;
    Image::free();
    return EXIT_SUCCESS;
}