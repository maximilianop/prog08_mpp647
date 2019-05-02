//
// Created by paxm on 5/1/19.
//

#ifndef PROJECT_8_HASH_H
#define PROJECT_8_HASH_H

#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Hash {
    private:

        struct key {
            int fileNum;
            key* next;
        };

        int numFiles;
        int hashSize;
        //2-D array with that will hold the amount of collisions
        int** collisions;

        //array of key pointers (hash table)
         key** hashTable;

    public:
        Hash();

        Hash(int numFiles, int hashSize);

        int getArraySize(){
            return numFiles;
        }

        int getNumColl (int i, int j){
            return collisions[i][j];
        }

        unsigned int createHashKey(string const &key);

        void storeHash(int key, int fileNum);

        void addPlagiarism();



};
#endif //PROJECT_8_HASH_H
