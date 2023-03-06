#ifndef LANCEUR_RAYONS_SCENE_H
#define LANCEUR_RAYONS_SCENE_H

#include <string>
#include "../triplet/Color.h"
#include "../Camera.h"
#include "../object3d/Object3D.h"
#include "../light/Light.h"
#include "../Image.h"

class Scene {
private:
    unsigned int width, height, nbLights, maxLights;
    unsigned long long nbObjects, maxObjects, nbVertices, maxVertices;
    std::string outputPath;
    Color ambient;
    Camera *camera;
    Object3D **objects;
    Light **lights;
    Point **vertices;
    bool shadow;
private:
    Color getColor(const Object3D* o, const Point& p) const;
public:
    Scene(unsigned int width, unsigned int height);
    ~Scene();
    void setOutputPath(std::string path);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const std::string &getOutputPath() const;
    void addLight(const Light *light);
    void addObject(Object3D* o);
    unsigned int getNbLight() const;
    unsigned long long int getNbObjects() const;
    void setAmbient(const Color& color);
    void setCamera(const Camera& newCamera);
    Color getAmbient() const;
    void upMaxVertices(unsigned long long max);
    void addVertex(const Point& v);
    Point* getVertex(unsigned long long i);
    double* getDimPixel();
    Vector getVectorD(double maxX, double maxY, unsigned int x, unsigned int y);
    void exportPNG();
    void setShadow(bool shadow);
    void pixelProcessing(Image *img, double *pixDim, unsigned int i, unsigned int j);
};

#endif //LANCEUR_RAYONS_SCENE_H
