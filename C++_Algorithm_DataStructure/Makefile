CFLAGS = -std=c++14 -g -Wall

###############
# Binary File #
###############
all: Main.o Sort.o Activity.o 
	g++ $(CFLAGS) -o Alg Main.o Sort.o Activity.o

test: Test.o LinkedList.o Sort.o Show.o BST.o
	g++ $(CFLAGS) -o test Test.o LinkedList.o Sort.o Show.o BST.o

###############
# Object file #
###############
Main.o: Main.cpp
	g++ $(CFLAGS) -c Main.cpp

Sort.o: Sort.h Sort.cpp
	g++ $(CFLAGS) -c Sort.cpp

Activity.o: Activity.h Activity.cpp consts.h
	g++ $(CFLAGS) -c Activity.cpp

Test.o: Test.h Test.cpp LinkedList.hpp LinkedList.cpp Sort.h Show.h BST.hpp BST.cpp
	g++ $(CFLAGS) -c Test.cpp

LinkedList.o: LinkedList.hpp LinkedList.cpp consts.h
	g++ $(CFLAGS) -o $@ -c LinkedList.hpp

BST.o: BST.hpp BST.cpp consts.h
	g++ $(CFLAGS) -o $@ -c BST.hpp

Show.o: Show.h Show.cpp
	g++ $(CFLAGS) -c Show.cpp

#########
# clean #
#########
clean:
	rm *.o Alg test
