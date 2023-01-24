#include "CompareImage.h"
#include <iostream>
#include "FreeImage.h"

bool CompareImage::compare(const std::string& imgPath1, const std::string& imgPath2) {
    RGBQUAD clr1, clr2;
    FIBITMAP *img1=nullptr, *img2=nullptr;
    unsigned long long error=0;
    bool status=false;
    if (FreeImage_GetFIFCount()<=0) {
        std::cerr << "FreeImage not initialized !" << std::endl;
        goto quit;
    }
    img1 = FreeImage_Load(FIF_PNG, imgPath1.c_str(),0);
    if (!img1) {
        std::cerr << "failed load image 1 ! (" << imgPath1 << ")" << std::endl;
        goto quit;
    }
    img2 = FreeImage_Load(FIF_PNG, imgPath2.c_str(),0);
    if (!img2) {
        std::cerr << "failed load image 2 ! (" << imgPath2 << ")" << std::endl;
        goto quit;
    }
    if (FreeImage_GetWidth(img1) != FreeImage_GetWidth(img2)) {
        std::cerr << "Width image is different !" << std::endl;
        goto quit;
    }
    if (FreeImage_GetHeight(img1) != FreeImage_GetHeight(img2)) {
        std::cerr << "Height image is different !" << std::endl;
        goto quit;
    }
    for (unsigned x=0; x<FreeImage_GetWidth(img1); x++) {
        for (unsigned y=0; y<FreeImage_GetHeight(img1); y++) {
            FreeImage_GetPixelColor(img1,x,y,&clr1);
            FreeImage_GetPixelColor(img2,x,y,&clr2);
            if (clr1.rgbRed != clr2.rgbRed || clr1.rgbGreen != clr2.rgbGreen || clr1.rgbBlue != clr2.rgbBlue) error++;
        }
    }
    std::cout << ((error>1000) ? "KO" : "OK") << std::endl << error << std::endl;
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