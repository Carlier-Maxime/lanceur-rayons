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
    bool pDotP;
    char* dt1 = strtok(argv[1],",");
    char* op = strtok(nullptr,",");
    char* dt2 = strtok(nullptr,",");
    t1 = buildTriplet(dt1);
    t2 = buildTriplet(dt2);
    bool notT2 = strcmp(op,"mul_ptr")==0 || strcmp(op,"len")==0 || strcmp(op,"hat_ptr")==0;
    if (!t1 || (!t2 && !notT2) || (t2 && notT2)) goto finish;
    if (strcmp(op,"mul_ptr")==0) a = strtod(dt2, nullptr);
    if (strcmp(op,"add")==0) t3 = t1->add(t2);
    else if (strcmp(op,"sub")==0) t3 = t1->sub(t2);
    else if (strcmp(op,"mul_ptr")==0) t3 = t1->mul_ptr(a);
    else if (strcmp(op,"dot")==0) b = t1->dot(t2);
    else if (strcmp(op,"cross")==0) t3 = t1->cross(t2);
    else if (strcmp(op,"times")==0) t3 = t1->times(t2);
    else if (strcmp(op,"len")==0) b = t1->len();
    else if (strcmp(op,"hat_ptr")==0) t3 = t1->hat_ptr();
    else goto finish;
    pDotP = (strcmp(op,"dot")==0 && t1->type()=='P' && t2 && t2->type()=='P');
    if ((t3 && t3->type()=='T') || pDotP) std::cout << "Interdit" << std::endl;
    else if (strcmp(op,"dot")==0 || strcmp(op,"len")==0) std::cout << b << ((int) b == b ? ".0" : "") << std::endl;
    else if (t3) std::cout << t3->toString() << std::endl;
    else goto finish;
    status = EXIT_SUCCESS;
    finish:
    if (status!=EXIT_SUCCESS) std::cout << "Interdit" << std::endl;
    delete t1;
    delete t2;
    delete t3;
    return status;
}
