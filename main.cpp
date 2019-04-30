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

    //is going to make all the chunks for all the files
    first.makeChunks();
    
    return 0;
}