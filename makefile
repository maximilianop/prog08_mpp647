final: plagiarismCatcher.o directory.o hash.o
	g++ -std=c++11 -o plagiarismCatcher plagiarismCatcher.o directory.o hash.o
driver: plagiarismCatcher.cpp directory.h hash.h
	g++ -std=c++11 -c plagiarismCatcher.cpp
directory.o: directory.cpp directory.h
	g++ -std=c++11 -c directory.cpp
hash.o: hash.cpp hash.h
	g++ -std=c++11 -c hash.cpp
clean:
	-rm *.o $(objects)
