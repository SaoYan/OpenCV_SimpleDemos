INCLUDE = $(shell pkg-config opencv-3.3.0 --cflags)
LIBS = $(shell pkg-config opencv-3.3.0 --libs)

all: opencv_exp

opencv_exp: main.o colorhistogram.o contentfinder.o
	g++ -o opencv_exp main.o colorhistogram.o contentfinder.o $(INCLUDE) $(LIBS)

main.o: main.cpp
	g++ -c main.cpp $(INCLUDE) $(LIBS)

colorhistogram.o: colorhistogram.cpp colorhistogram.h
	g++ -c colorhistogram.cpp $(INCLUDE) $(LIBS)

contentfinder.o: contentfinder.cpp contentfinder.h
	g++ -c contentfinder.cpp $(INCLUDE) $(LIBS)

clean:
	rm -f *.o opencv_exp
