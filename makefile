final: main.o directory.o
	g++ -std=c++11 -o main main.o directory.o
driver: main.cpp directory.h
	g++ -std=c++11 -c main.cpp
directory.o: directory.cpp directory.h
	g++ -std=c++11 -c directory.cpp
