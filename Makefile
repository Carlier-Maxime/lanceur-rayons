CC := g++
DEBUG ?= 1
ifeq '$(DEBUG)' '1'
	CFLAGS ?= -Wall -MMD -g
else
	CFLAGS ?= -Wall -MMD -O3
endif
od = bin/obj
odl = $(od)/light
odo = $(od)/object3d
ods = $(od)/scene
odt = $(od)/triplet
src = src
CMP_OBJS = $(od)/Image.o $(od)/Exceptions.o $(odt)/Color.o $(odt)/Triplet.o
MTH_OBJS = $(odt)/Triplet.o $(odt)/Color.o $(odt)/Point.o $(odt)/Vector.o $(od)/Exceptions.o
OBJECTS = $(od)/Exceptions.o $(odt)/Triplet.o $(odt)/Color.o $(ods)/Scene.o $(odt)/Point.o $(odt)/Vector.o $(ods)/SceneBuilder.o $(ods)/SceneLoader.o $(od)/Camera.o $(odo)/Object3D.o $(odo)/Sphere.o $(odo)/Triangle.o $(odo)/Plane.o $(odl)/Light.o $(odl)/LPoint.o $(odl)/LDirectional.o $(od)/Image.o
lib = -lfreeimage
include_dir =
lib_dir =

.PHONY: all clean mrProper
.PRECIOUS: $(od)/%.o

all : bin/compareImage bin/testTriplet bin/testSceneLoader bin/rayTracer

bin/compareImage : $(od)/compareImage.o $(CMP_OBJS)
	$(CC) $^ -o $@ $(lib) $(include_dir) $(lib_dir)

bin/testTriplet : $(odt)/testTriplet.o $(MTH_OBJS)
	$(CC) $^ -o $@ $(lib) $(include_dir) $(lib_dir)

bin/testSceneLoader : $(ods)/testSceneLoader.o $(OBJECTS)
	$(CC) $^ -o $@ $(lib) $(include_dir) $(lib_dir)

bin/% : $(od)/%.o $(OBJECTS)
	$(CC) $^ -o $@ $(lib) $(include_dir) $(lib_dir)

$(od)/%.o : $(src)/%.cpp
	@mkdir -p $(od)
	@mkdir -p $(odl)
	@mkdir -p $(odo)
	@mkdir -p $(ods)
	@mkdir -p $(odt)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm bin/obj -r

mrProper:
	rm bin -r