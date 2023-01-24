#include "CompareImage.h"
#include <iostream>
#include "FreeImage.h"

bool CompareImage::compare(std::string imgPath1, std::string imgPath2) {
    return true;
}

int main(int argc, char* argv[]) {
    int status = EXIT_FAILURE;
    if (argc<3) {
        std::cerr << "Argument missing !" << std::endl;
        goto quit;
    }
    FreeImage_Initialise();
    if (!CompareImage::compare(argv[1],argv[2])) goto quit;
    status=EXIT_SUCCESS;
quit:
    FreeImage_DeInitialise();
    return status;
}