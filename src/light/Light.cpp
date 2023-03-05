#include "Light.h"

Light::Light(const Color &color) : color(color) {}

Color Light::getColor() const {
    return color;
}

Light::~Light() = default;
