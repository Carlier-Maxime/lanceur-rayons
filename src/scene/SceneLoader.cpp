#include <sstream>
#include <fstream>
#include "SceneLoader.h"
#include "../Exceptions.h"

SceneLoader::SceneLoader(const std::string& filepath) : builder(nullptr) {
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
                else if (word=="shadow") shadow();
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
    try {builder = new SceneBuilder(getUint(), getUint()); builderIsInit=true;}
    catch (std::exception& e) {throw SyntaxException("in size");}
}

void SceneLoader::output() {
    try {
        std::string word = getWord();
        if (!builder) throw SyntaxException("output before size !");
        if (!word.empty()) builder->output(word);
    } catch (std::exception& e) {throw SyntaxException("in output");}
}

void SceneLoader::camera() {
    if (!builder) throw SyntaxException("camera before size");
    Point from = Point(getTriplet());
    Point at = Point(getTriplet());
    Vector up = Vector(getTriplet());
    double fov = getDouble();
    try {builder->camera(from,at, up, fov);}
    catch (std::exception& e) {throw SyntaxException("in camera");}
}

void SceneLoader::ambient() {
    if (!builder) throw SyntaxException("ambient before size");
    try {builder->ambient(Color(getTriplet()));}
    catch (std::exception& e) {throw SyntaxException("in ambient");}
}

void SceneLoader::diffuse() {
    if (!builder) throw SyntaxException("diffuse before size");
    try {builder->diffuse(Color(getTriplet()));}
    catch (std::exception& e) {throw SyntaxException("in diffuse");}
}

void SceneLoader::specular() {
    if (!builder) throw SyntaxException("specular before size");
    try {builder->specular(Color(getTriplet()));}
    catch (std::exception& e) {throw SyntaxException("in specular");}
}

void SceneLoader::shininess() {
    if (!builder) throw SyntaxException("shininess before size");
    try {builder->shininess(getUint());}
    catch (std::exception& e) {throw SyntaxException("in shininess");}
}

void SceneLoader::directional() {
    if (!builder) throw SyntaxException("directional before size");
    Vector direction = Vector(getTriplet());
    Color color = Color(getTriplet());
    try {builder->directional(direction, color);}
    catch (std::exception& e) {throw SyntaxException("in directional");}
}

void SceneLoader::point() {
    if (!builder) throw SyntaxException("point before size");
    Point pos = Point(getTriplet());
    Color color = Color(getTriplet());
    try {builder->point(pos,color);}
    catch (std::exception& e) {throw SyntaxException("in point");}
}

void SceneLoader::maxverts() {
    if (!builder) throw SyntaxException("maxverts before size");
    try {builder->maxverts(getUint());}
    catch (std::exception& e) {throw SyntaxException("in maxverts");}
}

void SceneLoader::vertex() {
    if (!builder) throw SyntaxException("vertex before size");
    try {builder->vertex(Point(getTriplet()));}
    catch (std::exception& e) {throw SyntaxException("in vertex");}
}

void SceneLoader::tri() {
    if (!builder) throw SyntaxException("tri before size");
    uint iv1 = getUint();
    uint iv2 = getUint();
    uint iv3 = getUint();
    try {builder->tri(iv1, iv2, iv3);}
    catch (std::exception& e) {throw SyntaxException("in tri");}
}

void SceneLoader::sphere() {
    if (!builder) throw SyntaxException("sphere before size");
    Point center = Point(getTriplet());
    try {builder->sphere(center, getDouble());}
    catch (std::exception& e) {throw SyntaxException("in sphere");}
}

void SceneLoader::plane() {
    if (!builder) throw SyntaxException("plane before size");
    Point pos = Point(getTriplet());
    Vector normal = Vector(getTriplet());
    try {builder->plane(pos, normal);}
    catch (std::exception& e) {throw SyntaxException("in plane");}
}

void SceneLoader::shadow() {
    try {builder->shadow(getWord()=="true");}
    catch (std::exception& e) {throw SyntaxException("in plane");}
}

SceneBuilder* SceneLoader::getBuilder() {
    return builder;
}

Triplet SceneLoader::getTriplet() {
    double x=getDouble();
    double y=getDouble();
    double z=getDouble();
    return {x, y, z};
}
