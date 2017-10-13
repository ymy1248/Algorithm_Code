all: Main.o Sort.o UI.o
	g++ -std=c++14 -o Alg Main.o Sort.o UI.o

Main.o: Main.cpp
	g++ -std=c++14 -c Main.cpp

Sort.o: Sort.h Sort.cpp
	g++ -std=c++14 -c Sort.cpp

UI.o: UI.h UI.cpp consts.h
	g++ -std=c++14 -c UI.cpp

clean:
	rm *.o Alg 
