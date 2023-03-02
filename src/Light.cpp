#include "Light.h"

Light::Light(const Color &color) : color(new Color(color)) {}

Color *Light::getColor() const {
    return color;
}

Light::~Light() {
    delete color;
}
