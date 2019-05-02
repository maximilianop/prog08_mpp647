//
// Created by paxm on 5/1/19.
//

#include "hash.h"

using namespace std;

Hash::Hash(int numFiles, int hashSize){
    this->hashSize = hashSize;
    this->numFiles = numFiles;

    collisions = new int*[numFiles];
    for (int i = 0; i < numFiles; i++){
        collisions[i] = new int[numFiles];
    }

    for (int i = 0; i < numFiles; i++){
        for (int j = 0; j < numFiles; j++){
            collisions[i][j] = 0;
        }
    }

    hashTable = new key*[hashSize];
    for(int i = 0; i < hashSize; i++){
        hashTable[i] = nullptr;
    }
}

unsigned int Hash::createHashKey(string const &key){
    unsigned int hashValue = 5;
    int exponent = 3;
    for(int i = 0; i < key.size()-1; i++) {
        //calculates exponent
        for (int j = 0; j < i-1; j++){
            exponent = exponent*3;
        }

        hashValue += hashValue*(hashValue - i -1)*exponent;
        exponent = 3;
        hashValue = hashValue % hashSize;
    }
    return hashValue;
}

void Hash::storeHash(int index, int fileNum){
    key *temp = hashTable[index];

    if (temp != NULL){
        while (temp->fileNum != fileNum){
            if (temp->next == nullptr){
                key *newNode = new key;
                newNode->next = nullptr;
                newNode->fileNum = fileNum;
                temp->next = newNode;
            }
            temp = temp->next;
        }
    } else {
        key *newNode = new key;
        newNode->next = nullptr;
        newNode->fileNum = fileNum;
        hashTable[index] = newNode;
    }
}

void Hash::addPlagiarism (){
    key* temp;
    key* temp2;
   for (int i = 0; i < hashSize; i++){
       temp = hashTable[i];
       while (temp != nullptr){
           temp2 = hashTable[i]->next;
           while (temp2 != nullptr) {
               collisions[temp->fileNum][temp2->fileNum] += 1;
               temp2 = temp2 -> next;
           }
           temp = temp->next;
       }
   }
}
