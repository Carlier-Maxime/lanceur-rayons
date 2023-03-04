#include "Image.h"
#include <FreeImage.h>
#include <utility>
#include "Exceptions.h"

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
    if (!isInit) throw ImageException("Not initialized !");
    this->path = "";
    img = FreeImage_Allocate((int) width,(int) height,24);
    if (!img) throw ImageException("Allocate failed !");
}

Image::Image(const std::string& path) {
    if (!isInit || path.empty()) throw ImageException("Not initialized !");
    this->path = path;
    img = FreeImage_Load(FIF_PNG,path.c_str());
    if (!img) throw ImageException("Load image failed !");
}

Color Image::getColorPixel(uint x, uint y) {
    RGBQUAD c;
    if (!FreeImage_GetPixelColor(img,x,y,&c)) throw ImageException("Get pixel color failed !");
    return {c.rgbRed,c.rgbGreen,c.rgbBlue};
}

void Image::setColorPixel(uint x, uint y, Color clr) {
    RGBQUAD c = {clr.getB255(),clr.getG255(),clr.getR255()};
    if (!FreeImage_SetPixelColor(img,x,y,&c)) throw ImageException("Set Pixel Color failed !");
}

unsigned long long Image::compare(Image *image) {
    unsigned long long error=0;
    if (getWidth() != image->getWidth() || getHeight() != image->getHeight())
        return ((getWidth()>image->getWidth()) ? getWidth()-image->getWidth() : image->getWidth()-getWidth())*((getHeight()>image->getHeight()) ? getHeight()-image->getHeight() : image->getHeight()-getHeight());
    auto *diff = new Image(getWidth(),getHeight());
    for (unsigned x=0; x<getWidth(); x++) {
        for (unsigned y=0; y<getHeight(); y++) {
            Color clr1 = getColorPixel(x,y);
            Color clr2 = image->getColorPixel(x,y);
            Color clrD = clr1.difference(clr2);
            if (clrD != Color(0.,0.,0.)) error++;
            diff->setColorPixel(x,y,clrD);
        }
    }
    diff->setPath("diff.png");
    diff->save();
    delete diff;
    return error;
}

Image::~Image() {
    FreeImage_Unload(img);
}

void Image::setPath(std::string newPath) {
    this->path = std::move(newPath);
}

void Image::save() {
    if (path.empty()) throw ImageException("output path is empty !");
    if (!FreeImage_Save(FIF_PNG,img,path.c_str())) throw ImageException("Save failed !");
}

unsigned Image::getWidth() {
    return FreeImage_GetWidth(img);
}

unsigned Image::getHeight() {
    return FreeImage_GetHeight(img);
}