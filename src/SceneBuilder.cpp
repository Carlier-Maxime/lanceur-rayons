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

SceneBuilder SceneBuilder::size(unsigned int width, unsigned int height) {
    return *this;
}

void SceneBuilder::size(std::istream& is) {
    try {
        std::string word;
        getline(is,word,' ');
        unsigned int width = std::stoul(word);
        getline(is,word,' ');
        unsigned int height = std::stoul(word);
        size(width,height);
    } catch (std::exception& e) {throw SyntaxException("in size");}
}

void SceneBuilder::output(std::istream &is) {

}

void SceneBuilder::camera(std::istream &is) {

}

void SceneBuilder::ambient(std::istream &is) {

}

void SceneBuilder::diffuse(std::istream &is) {

}

void SceneBuilder::specular(std::istream &is) {

}

void SceneBuilder::shininess(std::istream &is) {

}

void SceneBuilder::directional(std::istream &is) {

}

void SceneBuilder::point(std::istream &is) {

}

void SceneBuilder::maxverts(std::istream &is) {

}

void SceneBuilder::vertex(std::istream &is) {

}

void SceneBuilder::tri(std::istream &is) {

}

void SceneBuilder::sphere(std::istream &is) {

}

void SceneBuilder::plane(std::istream &is) {

}

SceneBuilder SceneBuilder::output(const std::string& outputPath) {
    return *this;
}

SceneBuilder
SceneBuilder::camera(double x, double y, double z, double u, double v, double w, double n, double o, double f) {
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
