#include <sstream>
#include <fstream>
#include "SceneLoader.h"
#include "Exceptions.h"

SceneLoader::SceneLoader(const std::string& filepath) : builder({0,0}) {
    std::ifstream file(filepath);
    if (!file.is_open()) throw FileException("Open file failed");
    std::string line, word;
    unsigned long long idLine=0;
    builderIsInit = false;
    while (getline(file,line)) {
        idLine++;
        ss = std::stringstream(line);
        getline(ss,word,' ');
        if (line.empty()) continue;
        try {
            if (word[0]=='#' || word.empty()) continue;
            else if (word=="size") size();
            else if (builderIsInit) {
                if (word=="output") output();
                else if (word=="camera") camera();
                else if (word=="ambient") ambient();
                else if (word=="diffuse") diffuse();
                else if (word=="specular") specular();
                else if (word=="shininess") shininess();
                else if (word=="directional") directional();
                else if (word=="point") point();
                else if (word=="maxverts") maxverts();
                else if (word=="vertex") vertex();
                else if (word=="tri") tri();
                else if (word=="sphere") sphere();
                else if (word=="plane") plane();
            } else throw SyntaxException("Invalid argument !");
        } catch (SyntaxException& e){e.setLine(idLine); throw;}
    }
    file.close();
    if (!builderIsInit) throw SyntaxException("Argument size not found !");
}

std::string SceneLoader::getWord() {
    std::string word;
    getline(ss,word,' ');
    return word;
}

unsigned int SceneLoader::getUint() {
    return std::stoul(getWord());
}

double SceneLoader::getDouble() {
    return std::stod(getWord());
}

void SceneLoader::size() {
    try {builder = SceneBuilder(getUint(), getUint()); builderIsInit=true;}
    catch (std::exception& e) {throw SyntaxException("in size");}
}

void SceneLoader::output() {
    try {
        std::string word = getWord();
        if (!word.empty()) builder.output(word);
    } catch (std::exception& e) {throw SyntaxException("in output");}
}

void SceneLoader::camera() {
    try {builder.camera(getDouble(),getDouble(),getDouble(),getDouble(),getDouble(),getDouble(),getDouble(),getDouble(),getDouble(),getDouble());}
    catch (std::exception& e) {throw SyntaxException("in camera");}
}

void SceneLoader::ambient() {
    try {builder.ambient(getDouble(), getDouble(), getDouble());}
    catch (std::exception& e) {throw SyntaxException("in ambient");}
}

void SceneLoader::diffuse() {
    try {builder.diffuse(getDouble(), getDouble(), getDouble());}
    catch (std::exception& e) {throw SyntaxException("in diffuse");}
}

void SceneLoader::specular() {
    try {builder.specular(getDouble(), getDouble(), getDouble());}
    catch (std::exception& e) {throw SyntaxException("in specular");}
}

void SceneLoader::shininess() {
    try {builder.shininess(getUint());}
    catch (std::exception& e) {throw SyntaxException("in shininess");}
}

void SceneLoader::directional() {
    try {builder.directional(getDouble(), getDouble(), getDouble(), getDouble(), getDouble(), getDouble());}
    catch (std::exception& e) {throw SyntaxException("in directional");}
}

void SceneLoader::point() {
    try {builder.point(getDouble(), getDouble(), getDouble(), getDouble(), getDouble(), getDouble());}
    catch (std::exception& e) {throw SyntaxException("in point");}
}

void SceneLoader::maxverts() {
    try {builder.maxverts(getUint());}
    catch (std::exception& e) {throw SyntaxException("in maxverts");}
}

void SceneLoader::vertex() {
    try {builder.vertex(getDouble(), getDouble(), getDouble());}
    catch (std::exception& e) {throw SyntaxException("in vertex");}
}

void SceneLoader::tri() {
    try {builder.tri(getUint(), getUint(), getUint());}
    catch (std::exception& e) {throw SyntaxException("in tri");}
}

void SceneLoader::sphere() {
    try {builder.sphere(getDouble(), getDouble(), getDouble(), getDouble());}
    catch (std::exception& e) {throw SyntaxException("in sphere");}
}

void SceneLoader::plane() {
    try {builder.plane(getDouble(), getDouble(), getDouble(), getDouble(), getDouble(), getDouble());}
    catch (std::exception& e) {throw SyntaxException("in plane");}
}

SceneBuilder SceneLoader::getBuilder() {
    return builder;
}
