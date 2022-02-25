#include <fstream>
#include <iostream>
#include "fileHeaders.hpp"

void readFile(char* infile, std::ostream& out) {
    std::string str;
    std::ifstream in(infile);
    while (getline(in, str)) {
        out<<str<<std::endl;
    }
    return;
}

void readFile(std::string infile, std::ostream& out) {
    std::string str;
    std::ifstream in(infile);
    while (getline(in, str)) {
        out<<str<<std::endl;
    }
    return;
}