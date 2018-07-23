all: utgj utpolygon utexp
utgj: main.o
	g++ -o utgj main.o -lgtest
main.o: main.cpp Vector.h utVector.h Matrix.h utMatrix.h
	g++ -c main.cpp
utpolygon: mainPolygon.o
		g++ -o utpolygon mainPolygon.o -lgtest
mainPolygon.o: Polygon.h Vector.h Matrix.h utPolygon.h
	g++ -c mainPolygon.cpp
utexp: mainExp.o
		g++ -o utexp mainExp.o -lgtest
mainExp.o: mainExp.cpp utExp.h
		g++ -c mainExp.cpp
clean:
	rm -f main.o utgj mainPolygon.o utpolygon mainExp.o utexp
