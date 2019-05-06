#include "directory.h"
#include "hash.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    static const unsigned int SM_HASH = 1000000;
    static const unsigned int MED_HASH = 10000000;
    static const unsigned int SM_DIR = 30;
    static const unsigned int MED_DIR = 50;
    unsigned int sizeOfTable;

    Directory first(argv[1], atoi(argv[2]));

    //adds all files to the vector of structs
    first.addFiles();

    //reads all the files and fixes all the words (no punctuation, random characters, etc.) then puts those words into a vector
    for (int i = 0; i < first.getFiles().size(); i++){
        first.readFile(i);
    }

    //make all the chunks for all the files
    first.makeChunks();

    //add all chunks to hash table
    if (first.getFiles().size() > SM_DIR){
        sizeOfTable = MED_HASH;
    } else if (first.getFiles().size() <= MED_DIR){
        sizeOfTable = SM_HASH;
    }

    Hash hashTable(first.getFiles().size(), sizeOfTable);

    for (int i = 0; i < first.getFiles().size(); i++){
        int key;
        while (!first.getFiles()[i].chunks.empty()) {
            key = hashTable.createHashKey(first.getFiles()[i].chunks.front());
            hashTable.storeHash(key, i);
            first.getFiles()[i].chunks.pop();
        }
    }

    //go through hash function and add all collisions
    hashTable.addToHash();

    //prints the collisions output

    for(int i = 0; i < hashTable.getArraySize(); i++){
        for (int j = 0; j < hashTable.getArraySize(); j++){
            if (hashTable.getNumColl(i, j) > atoi(argv[3])) {
                //switch this line to adding to a vector that will be added to in order
                hashTable.addPlagiarism( first.getFileName(i), first.getFileName(j), i, j );
            }
        }
    }
    hashTable.sortPlagPrint();


    return 0;
}
