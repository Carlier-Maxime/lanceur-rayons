all : bin/compareImage

bin/compareImage : bin src/CompareImage.cpp
	g++ src/CompareImage.cpp -o bin/compareImage -lfreeimage -I3rdparty/include -L3rdparty/lib

bin :
	mkdir bin

clean:
	rm bin/* -r