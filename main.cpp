#include "directory.h"

using namespace std;

int main(int argc, char* argv[]) {
    Directory first(argv[1], atoi(argv[2]));

    //adds all files to the vector of structs
    first.addFiles();

    //prints all the files from the directory
    first.printFiles();

    //reads all the files and fixes all the words (no punctuation, random characters, etc.) then puts those words into a vector
    for(int i = 0; i < first.getFiles().size(); i++){
        first.readFile(i);
    }








    //reading the words from the file
//        vector<string> buf;
//        string file = dir + files[0];
//        first.readFile(file, buf);
//        queue<string> chunks;
//        string chunk = "";
//        for (int i = 0; i < buf.size() - (first.getChunkSize()-1); i++){
//            for (int j = i; j < i + first.getChunkSize(); j++){
//                chunk += buf[j];
//            }
//            chunks.push(chunk);
//            chunk = "";
//        }
    return 0;
}