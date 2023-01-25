#ifndef LANCEUR_RAYONS_IMAGE_H
#define LANCEUR_RAYONS_IMAGE_H

#include <string>
#include <FreeImage.h>

class Image {
private:
    static bool isInit;
    std::string path;
    FIBITMAP *img;
public:
    ~Image();
    Image(unsigned width, unsigned height);
    explicit Image(std::string path);
    unsigned long long compare(Image *image);
    RGBQUAD getColorPixel(int x, int y);
    void setColorPixel(int x, int y, RGBQUAD clr);
    void setPath(std::string newPath);
    void save();
    unsigned getWidth();
    unsigned getHeight();
    static void init();
    static void free();
};

#endif //LANCEUR_RAYONS_IMAGE_H
