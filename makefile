final: main.o directory.o hash.o
	g++ -std=c++11 -o plagiarismCatcher main.o directory.o hash.o
driver: main.cpp directory.h hash.h
	g++ -std=c++11 -c main.cpp
directory.o: directory.cpp directory.h
	g++ -std=c++11 -c directory.cpp
hash.o: hash.cpp hash.h
	g++ -std=c++11 -c hash.cpp
clean:
	-rm *.o $(objects)
