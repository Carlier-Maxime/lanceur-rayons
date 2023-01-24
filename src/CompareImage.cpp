#include "CompareImage.h"
#include <iostream>
#include "FreeImage.h"

bool CompareImage::compare(const std::string& imgPath1, const std::string& imgPath2) {
    FIBITMAP *img1=nullptr, *img2=nullptr;
    bool status=false;
    if (FreeImage_GetFIFCount()<=0) goto quit;
    img1 = FreeImage_Load(FIF_PNG, imgPath1.c_str(),0);
    if (!img1) goto quit;
    img2 = FreeImage_Load(FIF_PNG, imgPath2.c_str(),0);
    if (!img2) goto quit;
    status=true;
quit:
    FreeImage_Unload(img1);
    FreeImage_Unload(img2);
    return status;
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