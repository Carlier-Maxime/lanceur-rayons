all : bin/compareImage

bin/compareImage : bin src/CompareImage.cpp
	g++ src/CompareImage.cpp -o bin/compareImage -lfreeimage

bin :
	mkdir bin