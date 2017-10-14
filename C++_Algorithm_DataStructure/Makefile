all: Main.o Sort.o Activity.o
	g++ -std=c++14 -o Alg Main.o Sort.o Activity.o

Main.o: Main.cpp
	g++ -std=c++14 -c Main.cpp

Sort.o: Sort.h Sort.cpp
	g++ -std=c++14 -c Sort.cpp

Activity.o: Activity.h Activity.cpp consts.h
	g++ -std=c++14 -c Activity.cpp

clean:
	rm *.o Alg 
