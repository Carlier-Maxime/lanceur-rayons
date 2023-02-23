#include <cstdlib>
#include <iostream>
#include <cstring>
#include "Triplet.h"
#include "Vector.h"
#include "Point.h"
#include "Color.h"

Triplet* buildTriplet(const char* data) {
    const char d[] = " ";
    char* cdata = strdup(data);
    char type = strtok(cdata,d)[0];
    double coo[3];
    for (double & i : coo) {
        char* tmp = strtok(nullptr, d);
        if (!tmp) {
            free(cdata);
            return nullptr;
        }
        i=strtod(tmp, nullptr);
    }
    free(cdata);
    double x=coo[0],y=coo[1],z=coo[2];
    switch (type) {
        case 'T': return new Triplet(x,y,z);
        case 'P': return new Point(x,y,z);
        case 'V': return new Vector(x,y,z);
        case 'C': return new Color(x,y,z);
        default: return nullptr;
    }
}

int main(int argc, char *argv[]) {
    int status = EXIT_FAILURE;
    if (argc<2 || argc>2) return EXIT_FAILURE;
    Triplet *t1,*t2,*t3=nullptr;
    double a=0,b=0;
    char* dt1 = strtok(argv[1],",");
    char* op = strtok(nullptr,",");
    char* dt2 = strtok(nullptr,",");
    t1 = buildTriplet(dt1);
    t2 = buildTriplet(dt2);
    if (!t1 || (!t2 && strcmp(op,"mul")!=0 && strcmp(op,"len")!=0 && strcmp(op,"hat")!=0)) goto finish;
    if (strcmp(op,"mul")==0) a = strtod(dt2, nullptr);
    if (strcmp(op,"add")==0) t3 = t1->add(t2);
    else if (strcmp(op,"sub")==0) t3 = t1->sub(t2);
    else if (strcmp(op,"mul")==0) t3 = t1->mul(a);
    else if (strcmp(op,"dot")==0) b = t1->dot(t2);
    else if (strcmp(op,"cross")==0) t3 = t1->cross(t2);
    else if (strcmp(op,"times")==0) t3 = t1->times(t2);
    else if (strcmp(op,"len")==0) b = t1->len();
    else if (strcmp(op,"hat")==0) t3 = t1->hat();
    else goto finish;
    if (t3 && t3->type()=='T') std::cout << "Interdit" << std::endl;
    else if (strcmp(op,"dot")==0 || strcmp(op,"len")==0) std::cout << b << std::endl;
    else std::cout << t3->toString() << std::endl;
    status = EXIT_SUCCESS;
    finish:
    delete t1;
    delete t2;
    delete t3;
    return status;
}
