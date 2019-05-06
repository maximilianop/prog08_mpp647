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

// I decided to set it up by using 1 class called directory which holds all the information about all the files in that directory as well as the chunk size that the user chooses to use.
// There is a vector called allFiles which holds the information about the all the files in the directory. It is a vector of structs, where the struct is called file, and holds information specific
// to each file in the directory.
// The information in the struct includes the name of the file, a vector that holds all the fixed words from the file (no punctuation, no symbols, all lowercase, etc.) to make it easier to create chunks
// there is also a queue class that holds strings, this is where the chunks are stored. Since it is a queue i just pushed eached chunk, and then to hash the chunk we can just pop each chunk.
// The other information in the class is the chunkSize and the name of the directory
// if anything is confusing hit me up bro
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

        //initializes the class variables with the input from the user
        Directory(char* dirName, int chunkSize){
            this->dirName = dirName;
            this->chunkSize = chunkSize;
        }

        //getter for the vector holding all the structs with info on the files
        vector<files>& getFiles () {
            return allFiles;
        }

        string getFileName (int index){
            return allFiles[index].fileName;
        }

        //getter for the name of the directory (if needed)
        string getDirName (){
            return dirName;
        }

        //Goes through the directory and places all the files into the vector, each file gets it's own struct and is initialized with the name of the file
        int addFiles ();

        //reads file, corrects all the words (all lowercase, no punctuation, etc.) and places each word into a vector
        void readFile (int fileNum);

        //prints all the file names in the directory (testing purposes)
        void printFiles ();

        //goes through the vector of fixed words and creates chunks of the input size for all the files
        void makeChunks ();

        ~Directory() = default;

};

#endif //PROJECT_8_FILE_H
