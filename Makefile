CC := g++
DEBUG ?= 0
ifeq '$(DEBUG)' '1'
	CFLAGS ?= -Wall -MMD -g
else
	CFLAGS ?= -Wall -MMD
endif
od = bin/obj
OBJS_CMP_IMG = $(od)/CompareImage.o
lib = -lfreeimage
include_dir = -I3rdparty/include
lib_dir = -L3rdparty/lib

.PHONY: compareImage

all : compareImage

compareImage : $(OBJS_CMP_IMG)
	$(CC) $^ -o bin/compareImage $(lib) $(include_dir) $(lib_dir)

$(od)/%.o : src/%.cpp
	@mkdir -p $(od)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm bin/obj -r

mrProper:
	rm bin -r