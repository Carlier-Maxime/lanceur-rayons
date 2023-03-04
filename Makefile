CC := g++
DEBUG ?= 1
ifeq '$(DEBUG)' '1'
	CFLAGS ?= -Wall -MMD -g
else
	CFLAGS ?= -Wall -MMD
endif
od = bin/obj
src = src
CMP_OBJS = $(od)/Image.o $(od)/Exceptions.o $(od)/Color.o $(od)/Triplet.o
MTH_OBJS = $(od)/Triplet.o $(od)/Color.o $(od)/Point.o $(od)/Vector.o $(od)/Exceptions.o
OBJECTS = $(od)/Exceptions.o $(od)/Triplet.o $(od)/Color.o $(od)/Scene.o $(od)/Point.o $(od)/Vector.o $(od)/SceneBuilder.o $(od)/SceneLoader.o $(od)/Camera.o $(od)/Object3D.o $(od)/Sphere.o $(od)/Triangle.o $(od)/Plane.o $(od)/Light.o $(od)/LPoint.o $(od)/LDirectional.o $(od)/Image.o
lib = -lfreeimage
include_dir =
lib_dir =

.PHONY: all clean mrProper
.PRECIOUS: $(od)/%.o

all : bin/compareImage bin/testTriplet bin/testSceneLoader bin/rayTracer

bin/compareImage : $(od)/compareImage.o $(CMP_OBJS)
	$(CC) $^ -o $@ $(lib) $(include_dir) $(lib_dir)

bin/testTriplet : $(od)/testTriplet.o $(MTH_OBJS)
	$(CC) $^ -o $@ $(lib) $(include_dir) $(lib_dir)

bin/% : $(od)/%.o $(OBJECTS)
	$(CC) $^ -o $@ $(lib) $(include_dir) $(lib_dir)

$(od)/%.o : $(src)/%.cpp
	@mkdir -p $(od)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm bin/obj -r

mrProper:
	rm bin -r