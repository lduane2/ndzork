all: demo

demo: demo.o
	g++ -o demo demo.o -lncurses

demo.o: demo.cpp
	g++ -c demo.cpp --std=c++11

clean:
	rm *.o
	rm a.out
