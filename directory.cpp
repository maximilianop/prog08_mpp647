//
// Created by paxm on 4/24/19.
//
#include "directory.h"
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

int Directory::addFiles(){
    DIR *dp;
    struct dirent *dirp;
    int i = 0;
    if ((dp = opendir(dirName.c_str())) == NULL){
        cout << "Error(" << errno << ") opening " << dirName << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL){
        if ( strcmp(dirp->d_name,".") == 0 || strcmp(dirp->d_name, "..") == 0 ){

        }
        else {
            allFiles.push_back(files());
            allFiles[i].fileName = string(dirp->d_name);
            i += 1;
        }
    }
    closedir(dp);
    return 0;
}

void Directory::readFile(int fileNum) {
    ifstream file;
    file.open(dirName + allFiles[fileNum].fileName);
    string word;

    while (file >> word) {
        for (int i = 0; i < word.size(); i++) {
            if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    word[i] = word[i] + 32;
                }
            } else if (word[i] >= '0' && word[i] <= '9') {

            } else {
                word.erase(word.begin() + i);
                i -= 1;
            }
        }
        allFiles[fileNum].fixedWords.push_back(word);
        word = "";
    }
}

void Directory::printFiles () {
    for (int i = 0; i < allFiles.size(); i++){
        cout << allFiles[i].fileName << endl;
    }
}

queue<string> makeChunks (){

}