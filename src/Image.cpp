#include "Image.h"
#include <FreeImage.h>

#include <utility>

bool Image::isInit = false;

void Image::init() {
    FreeImage_Initialise();
    isInit=true;
}

void Image::free() {
    isInit=false;
    FreeImage_DeInitialise();
}

Image::Image(uint width, uint height) {
    if (!isInit) throw std::exception();
    this->path = "";
    img = FreeImage_Allocate((int) width,(int) height,24);
    if (!img) throw std::exception();
}

Image::Image(const std::string& path) {
    if (!isInit || path.empty()) throw std::exception();
    this->path = path;
    img = FreeImage_Load(FIF_PNG,path.c_str());
    if (!img) throw std::exception();
}

Color* Image::getColorPixel(uint x, uint y) {
    RGBQUAD c;
    FreeImage_GetPixelColor(img,x,y,&c);
    return new Color(c.rgbRed,c.rgbGreen,c.rgbBlue);
}

void Image::setColorPixel(uint x, uint y, Color *clr) {
    RGBQUAD c = {clr->getR(),clr->getG(),clr->getB()};
    FreeImage_SetPixelColor(img,x,y,&c);
}

unsigned long long Image::compare(Image *image) {
    Color *clr1, *clr2, *clrD = new Color(0,0,0);
    unsigned long long error=0;
    if (getWidth() != image->getWidth() || getHeight() != image->getHeight()) return -1;
    auto *diff = new Image(getWidth(),getHeight());
    for (unsigned x=0; x<getWidth(); x++) {
        for (unsigned y=0; y<getHeight(); y++) {
            clr1 = getColorPixel(x,y);
            clr2 = image->getColorPixel(x,y);
            if (clr1->getR() != clr2->getR() || clr1->getG() != clr2->getG() || clr1->getB() != clr2->getB()) {
                error++;
                clrD->setR((clr1->getR()>clr2->getR()) ? clr1->getR()-clr2->getR() : clr2->getR()-clr1->getR());
                clrD->setG((clr1->getG()>clr2->getG()) ? clr1->getG()-clr2->getG() : clr2->getG()-clr1->getG());
                clrD->setB((clr1->getB()>clr2->getB()) ? clr1->getB()-clr2->getB() : clr2->getB()-clr1->getB());
            } else clrD->setRGB(0,0,0);
            diff->setColorPixel(x,y,clrD);
        }
    }
    diff->setPath("diff.png");
    diff->save();
    return error;
}

Image::~Image() {
    FreeImage_Unload(img);
}

void Image::setPath(std::string newPath) {
    this->path = std::move(newPath);
}

void Image::save() {
    if (path.empty()) return;
    FreeImage_Save(FIF_PNG,img,path.c_str());
}

unsigned Image::getWidth() {
    return FreeImage_GetWidth(img);
}

unsigned Image::getHeight() {
    return FreeImage_GetHeight(img);
}
