all: Triangle.o TFractal.o
	g++ Triangle.o TFractal.o -o TFractal -lsfml-graphics -lsfml-window -lsfml-system

Triangle.o: Triangle.cpp Triangle.hpp
	g++ -c Triangle.cpp

TFractal.o: TFractal.cpp
	g++ -c TFractal.cpp

TFractal: Triangle.o TFractal.o
	g++ Triangle.o TFractal.o -o TFractal

clean:
	rm *.o TFractal
