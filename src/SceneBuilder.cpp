#include <fstream>
#include <iostream>
#include <sstream>
#include "SceneBuilder.h"
#include "Exceptions.h"

SceneBuilder::SceneBuilder(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) throw FileException("Open file failed");
    std::string line, word;
    unsigned long long idLine=0;
    scene = nullptr;
    while (getline(file,line)) {
        idLine++;
        std::stringstream ss(line);
        getline(ss,word,' ');
        if (line.empty()) continue;
        try {
            if (word[0]=='#' || word.empty()) continue;
            else if (word=="size") size(ss);
            else if (word=="output") output(ss);
            else if (word=="camera") camera(ss);
            else if (word=="ambient") ambient(ss);
            else if (word=="diffuse") diffuse(ss);
            else if (word=="specular") specular(ss);
            else if (word=="shininess") shininess(ss);
            else if (word=="directional") directional(ss);
            else if (word=="point") point(ss);
            else if (word=="maxverts") maxverts(ss);
            else if (word=="vertex") vertex(ss);
            else if (word=="tri") tri(ss);
            else if (word=="sphere") sphere(ss);
            else if (word=="plane") plane(ss);
            else throw SyntaxException("Unknown argument !");
        } catch (SyntaxException& e){e.setLine(idLine); throw;}
    }
    file.close();
}

Scene *SceneBuilder::build() {
    return scene;
}

std::string SceneBuilder::getWord(std::istream& is) {
    std::string word;
    getline(is,word,' ');
    return word;
}

unsigned int SceneBuilder::getUint(std::istream& is) {
    return std::stoul(getWord(is));
}

double SceneBuilder::getDouble(std::istream& is) {
    return std::stod(getWord(is));
}

void SceneBuilder::size(std::istream& is) {
    try {size(getUint(is), getUint(is));}
    catch (std::exception& e) {throw SyntaxException("in size");}
}

void SceneBuilder::output(std::istream &is) {
    try {
        std::string word = getWord(is);
        if (word.empty()) output("output.png");
        else output(word);
    } catch (std::exception& e) {throw SyntaxException("in output");}
}

void SceneBuilder::camera(std::istream &is) {
    try {camera(getDouble(is),getDouble(is),getDouble(is),getDouble(is),getDouble(is),getDouble(is),getDouble(is),getDouble(is),getDouble(is),getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in camera");}
}

void SceneBuilder::ambient(std::istream &is) {
    try {ambient(getDouble(is), getDouble(is), getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in ambient");}
}

void SceneBuilder::diffuse(std::istream &is) {
    try {diffuse(getDouble(is), getDouble(is), getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in diffuse");}
}

void SceneBuilder::specular(std::istream &is) {
    try {specular(getDouble(is), getDouble(is), getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in specular");}
}

void SceneBuilder::shininess(std::istream &is) {
    try {shininess(getUint(is));}
    catch (std::exception& e) {throw SyntaxException("in shininess");}
}

void SceneBuilder::directional(std::istream &is) {
    try {directional(getDouble(is), getDouble(is), getDouble(is), getDouble(is), getDouble(is), getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in directional");}
}

void SceneBuilder::point(std::istream &is) {
    try {point(getDouble(is), getDouble(is), getDouble(is), getDouble(is), getDouble(is), getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in point");}
}

void SceneBuilder::maxverts(std::istream &is) {
    try { maxverts(getUint(is));}
    catch (std::exception& e) {throw SyntaxException("in maxverts");}
}

void SceneBuilder::vertex(std::istream &is) {
    try {vertex(getDouble(is), getDouble(is), getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in vertex");}
}

void SceneBuilder::tri(std::istream &is) {
    try {tri(getUint(is), getUint(is), getUint(is));}
    catch (std::exception& e) {throw SyntaxException("in tri");}
}

void SceneBuilder::sphere(std::istream &is) {
    try {sphere(getDouble(is), getDouble(is), getDouble(is), getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in sphere");}
}

void SceneBuilder::plane(std::istream &is) {
    try {plane(getDouble(is), getDouble(is), getDouble(is), getDouble(is), getDouble(is), getDouble(is));}
    catch (std::exception& e) {throw SyntaxException("in plane");}
}

SceneBuilder SceneBuilder::size(unsigned int width, unsigned int height) {
    return *this;
}

SceneBuilder SceneBuilder::output(const std::string& outputPath) {
    return *this;
}

SceneBuilder
SceneBuilder::camera(double x, double y, double z, double u, double v, double w, double m, double n, double o, double f) {
    return *this;
}

SceneBuilder SceneBuilder::ambient(double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::diffuse(double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::specular(double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::shininess(unsigned int i) {
    return *this;
}

SceneBuilder SceneBuilder::directional(double x, double y, double z, double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::point(double x, double y, double z, double r, double g, double b) {
    return *this;
}

SceneBuilder SceneBuilder::maxverts(unsigned int max) {
    return *this;
}

SceneBuilder SceneBuilder::vertex(double x, double y, double z) {
    return *this;
}

SceneBuilder SceneBuilder::tri(unsigned int iv1, unsigned int iv2, unsigned int iv3) {
    return *this;
}

SceneBuilder SceneBuilder::sphere(double x, double y, double z, double r) {
    return *this;
}

SceneBuilder SceneBuilder::plane(double x, double y, double z, double u, double v, double w) {
    return *this;
}
