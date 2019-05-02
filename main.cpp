#include "directory.h"
#include "hash.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    static const int direc = 100000;

    Directory first(argv[1], atoi(argv[2]));

    //adds all files to the vector of structs
    first.addFiles();

    //prints all the files from the directory
//    first.printFiles();

    //reads all the files and fixes all the words (no punctuation, random characters, etc.) then puts those words into a vector
    for (int i = 0; i < first.getFiles().size(); i++){
        first.readFile(i);
    }

    //is going to make all the chunks for all the files
    first.makeChunks();

    //add all chunks to hash table
    Hash hashTable(first.getFiles().size(), direc);

    for (int i = 0; i < first.getFiles().size(); i++){
        int key;
        while (!first.getFiles()[i].chunks.empty()) {
            key = hashTable.createHashKey(first.getFiles()[i].chunks.front());
            hashTable.storeHash(key, i);
            first.getFiles()[i].chunks.pop();
        }
    }

    //go through hash function and add all collisions
    hashTable.addPlagiarism();

    //prints the collisions output
    for(int i = 0; i < hashTable.getArraySize(); i++){
        for (int j = 0; j < hashTable.getArraySize(); j++){
            if (hashTable.getNumColl(i, j) >= atoi(argv[3])) {
                cout << hashTable.getNumColl(i,j) << ": " << first.getFileName(i) << ", " << first.getFileName(j) << endl;
            }
        }
    }


    return 0;
}
