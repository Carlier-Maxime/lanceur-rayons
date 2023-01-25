#include "Image.h"

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
    img = FreeImage_Allocate(width,height,24);
    if (!img) throw std::exception();
}

Image::Image(std::string path) {
    if (!isInit || path.empty()) throw std::exception();
    this->path = path;
    img = FreeImage_Load(FIF_PNG,path.c_str());
    if (!img) throw std::exception();
}

RGBQUAD Image::getColorPixel(int x, int y) {
    RGBQUAD c;
    FreeImage_GetPixelColor(img,x,y,&c);
    return c;
}

void Image::setColorPixel(int x, int y, RGBQUAD clr) {
    FreeImage_SetPixelColor(img,x,y,&clr);
}

unsigned long long Image::compare(Image *image) {
    RGBQUAD clr1, clr2, clrD;
    unsigned long long error=0;
    if (getWidth() != image->getWidth() || getHeight() != image->getHeight()) return -1;
    Image *diff = new Image(getWidth(),getHeight());
    for (unsigned x=0; x<getWidth(); x++) {
        for (unsigned y=0; y<getHeight(); y++) {
            clr1 = getColorPixel(x,y);
            clr2 = image->getColorPixel(x,y);
            if (clr1.rgbRed != clr2.rgbRed || clr1.rgbGreen != clr2.rgbGreen || clr1.rgbBlue != clr2.rgbBlue) {
                error++;
                clrD.rgbRed = (clr1.rgbRed>clr2.rgbRed) ? clr1.rgbRed-clr2.rgbRed : clr2.rgbRed-clr1.rgbRed;
                clrD.rgbGreen = (clr1.rgbGreen>clr2.rgbGreen) ? clr1.rgbGreen-clr2.rgbGreen : clr2.rgbGreen-clr1.rgbGreen;
                clrD.rgbBlue = (clr1.rgbBlue>clr2.rgbBlue) ? clr1.rgbBlue-clr2.rgbBlue : clr2.rgbBlue-clr1.rgbBlue;
            } else clrD={0,0,0};
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
    this->path = newPath;
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
