//
// Created by paxm on 5/1/19.
//

#ifndef PROJECT_8_HASH_H
#define PROJECT_8_HASH_H

#include <string>
#include <queue>
#include <iostream>

using namespace std;
//this class holds all information about the hash table and other structures that might be needed/related to the hash table and processing the output of the program

class Hash {
    private:

        struct key {
            int fileNum;
            key* next;
        };

        struct output {
            string file1;
            string file2;
            int plag;
        };

        int numFiles;
        int hashSize;
        //2-D array with that will hold the amount of collisions
        int** collisions;

        //array of key pointers (hash table)
         key** hashTable;

         vector<output> result;

    public:
        Hash();

        //initializes the hash table and 2D array needed to store information on collisions as well as all other private variables
        Hash(int numFiles, int hashSize);

        //returns the dimension of the array
        int getArraySize(){
            return numFiles;
        }

        //
        int getNumColl (int i, int j){
            return collisions[i][j];
        }

        unsigned int createHashKey(string const &key);

        void storeHash(int key, int fileNum);

        void addToHash();

        void addPlagiarism(string file1, string file2, int i, int j);

        void sortPlagPrint();

        void swap(output &i,output &j);

        ~Hash() {
            for (int i = 0; i < numFiles; i++){
                    delete collisions[i];
            }
            delete collisions;

            key *temp = hashTable[0];
            for (int i = 0; i < hashSize; i++){
                while (temp != NULL){
                    key *temp2 = temp;
                    temp = temp->next;
                    delete temp2;
                }
                temp = hashTable[i];
            }

            delete hashTable;
        }

};
#endif //PROJECT_8_HASH_H
