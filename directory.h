//
// Created by paxm on 4/24/19.
//

#ifndef PROJECT_8_DIRECTORY_H
#define PROJECT_8_DIRECTORY_H

#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <queue>


using namespace std;

class Directory
{
    private:
        struct files {
            string fileName;
            vector<string> fixedWords;
            queue<string> chunks;
        };

        vector<files> allFiles;
        string dirName;
        int chunkSize;

    public:
        Directory();

        Directory(char* dirName, int chunkSize){
            this->dirName = dirName;
            this->chunkSize = chunkSize;
        }

        vector<files> getFiles () {
            return allFiles;
        }

        string getDirName (){
            return dirName;
        }

        //places all files from directory into a vector
        int addFiles ();

        //reads file and places all fixed words (all lowercase, no punctuation, etc.) into a vector
        void readFile (int fileNum);

        //prints all the file names in the directory
        void printFiles ();

};

#endif //PROJECT_8_FILE_H
