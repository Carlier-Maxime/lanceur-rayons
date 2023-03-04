#include "Scene.h"
#include "Exceptions.h"
#include "Image.h"
#include <cmath>


Scene::Scene(unsigned int width, unsigned int height) : width(width), height(height), nbLight(0), maxLight(0), nbObjects(0), maxObjects(0), outputPath("output.png"), ambient(nullptr), camera(nullptr), objects(nullptr) {}

Scene::~Scene() {
    for (unsigned long long i=0; i<nbObjects; i++) {
        delete objects[i];
    }
    free(objects);
}

void Scene::setOutputPath(std::string path) {
    outputPath = std::move(path);
}

unsigned int Scene::getWidth() const {
    return width;
}

unsigned int Scene::getHeight() const {
    return height;
}

const std::string &Scene::getOutputPath() const {
    return outputPath;
}

void Scene::addLight() {
    nbLight++;
}

void Scene::addObject(const Object3D* o) {
    if (nbObjects>=maxObjects) {
        Object3D** tmp = static_cast<Object3D**>(realloc(objects,maxObjects+128));
        if (!tmp) throw SceneException("Allocation failed !");
        objects = tmp;
        maxObjects+=128;
    }
    objects[nbObjects] = o->clone();
    nbObjects++;
}

unsigned int Scene::getNbLight() const {
    return nbLight;
}

unsigned long long int Scene::getNbObjects() const {
    return nbObjects;
}

void Scene::setAmbient(const Color& ambient) {
    this->ambient = new Color(ambient);
}

void Scene::setCamera(const Camera& camera) {
    this->camera = new Camera(camera);
}
double* Scene::getDimPixel(){
    double pHeight = tan((camera->getFov()/2));
    double pWidth = pHeight*(this->width/this->height);
    auto* pixDim = static_cast<double*>(malloc(2 * sizeof(double )));
    pixDim[0]=pHeight;
    pixDim[1]=pWidth;
    return pixDim;
}
Vector* Scene::getVectorD(int i,int j){
    double* pixDim = getDimPixel();
    double pixHeight= pixDim[0];
    double pixWidth= pixDim[1];
    double a = (pixWidth*(i-(width/2)+0.5))/(width/2);
    double b = (pixHeight*(j-(height/2)+0.5))/(height/2);
    Vector* u = dynamic_cast<Vector*>(camera->getOrthonormal()[0]);
    Vector* v = dynamic_cast<Vector*>(camera->getOrthonormal()[1]);
    Vector* w = dynamic_cast<Vector*>(camera->getOrthonormal()[2]);
    Vector* numD = dynamic_cast<Vector*>(u->mul(a)->add(v->mul(b))->sub(w));
    Vector* d= dynamic_cast<Vector*>(numD->hat());
    return d;
}

void Scene::exportPNG() {
    Image* img=new Image(width,height);
    for(unsigned int i=0;i<height;i++){
        for (unsigned int j=0; j<width; j++) {
            img->setColorPixel(j,i,{0.,0.,0.});
            for (unsigned long long k=0; k<nbObjects; k++) {
                Point* p = objects[k]->intersect(getVectorD(i,j),camera->getFrom());
                if(p){
                    img->setColorPixel(j,i,*ambient);
                    break;
                }
            }
        }
    }
    img->save();
}