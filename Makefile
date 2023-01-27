CC := g++
DEBUG ?= 1
ifeq '$(DEBUG)' '1'
	CFLAGS ?= -Wall -MMD -g
else
	CFLAGS ?= -Wall -MMD
endif
od = bin/obj
src = src
OBJECTS = $(od)/Exceptions.o $(od)/Triplet.o $(od)/Color.o $(od)/Image.o $(od)/Scene.o $(od)/SceneBuilder.o $(od)/SceneLoader.o
lib = -lfreeimage
include_dir = -I3rdparty/include
lib_dir = -L3rdparty/lib

.PHONY: all clean mrProper
.PRECIOUS: $(od)/%.o

all : bin/compareImage bin/main

bin/% : $(od)/%.o $(OBJECTS)
	$(CC) $^ -o $@ $(lib) $(include_dir) $(lib_dir)

$(od)/%.o : $(src)/%.cpp
	@mkdir -p $(od)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm bin/obj -r

mrProper:
	rm bin -r