#include <iostream>
#include <string.h>

#include "fileHeaders.hpp"

using namespace std;

int main (int argc, char* argv[]) {
    string version = "1.0.0";
    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            printHelpText();
        }
        else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
            cout<<"file-utils version: "<<version<<endl;
        }
        return 0;
    }
    else if (argc < 3) {
        cout<<"Error: missing command options. for help use command - file-utils -h";
        return 1;
    }
    else {
        if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "read") == 0) {
            readFile(argv[2], cout);
            return 1;
        }
    }
}