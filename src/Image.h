#ifndef LANCEUR_RAYONS_IMAGE_H
#define LANCEUR_RAYONS_IMAGE_H

#include <string>
#include "Color.h"
typedef struct FIBITMAP FIBITMAP;

class Image {
private:
    static bool isInit;
    std::string path;
    FIBITMAP *img;
public:
    ~Image();
    Image(unsigned width, unsigned height);
    explicit Image(const std::string& path);
    unsigned long long compare(Image *image);
    Color getColorPixel(uint x, uint y);
    void setColorPixel(uint x, uint y, Color clr);
    void setPath(std::string newPath);
    void save();
    unsigned getWidth();
    unsigned getHeight();
    static void init();
    static void free();
};

#endif //LANCEUR_RAYONS_IMAGE_H
