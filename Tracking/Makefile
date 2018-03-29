INCLUDE = $(shell pkg-config opencv --cflags)
LIBS = $(shell pkg-config opencv --libs)

all: opencv_exp

opencv_exp: main.o
	g++ -o opencv_exp main.o $(INCLUDE) $(LIBS)

main.o: main.cpp
	g++ -c main.cpp $(INCLUDE) $(LIBS)

clean:
	rm -f *.o opencv_exp
