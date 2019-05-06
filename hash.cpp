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
    unsigned int hashValue = 0;
    int exponent = 3;

    for(int i = 0; i < key.size()-1; i++) {
        //calculates exponent
        for (int j = 0; j < i-1; j++){
            exponent = exponent*3;
        }

        hashValue += key[key.size() - i -1]*exponent;
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

void Hash::addToHash (){
    key* temp;
    key* temp2;
   for (int i = 0; i < hashSize; i++){
       temp = hashTable[i];
       while (temp != nullptr){
           temp2 = temp->next;
           while (temp2 != nullptr) {
               collisions[temp->fileNum][temp2->fileNum] += 1;
               temp2 = temp2 -> next;
           }
           temp = temp->next;
       }
   }
}

void Hash::addPlagiarism(string file1, string file2, int i, int j){
    result.push_back(output());
    result[result.size()-1].file1 = file1;
    result[result.size()-1].file2 = file2;
    result[result.size()-1].plag = collisions[i][j];
}

void Hash::sortPlagPrint(){
    for (int i = 0; i < result.size(); i++){
        output *largest = &result[i];
        for (int j = i; j < result.size(); j++){
            if (result[j].plag > largest->plag){
                swap(*largest, result[j]);
                *largest = result[i];
            }
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i].plag << ": " << result[i].file1 << ", " << result[i].file2 << endl;
    }
}

void Hash::swap(output &i, output &j){
    output temp;
    temp.plag = j.plag;
    temp.file2 = j.file2;
    temp.file1 = j.file1;
    j.plag = i.plag;
    j.file2 = i.file2;
    j.file1 = i.file1;
    i.plag = temp.plag;
    i.file1 = temp.file1;
    i.file2 = temp.file2;
}

