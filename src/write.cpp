#include <fstream>
#include "fileHeaders.hpp"
#include <iostream>

void writeFile(char *outfile, char *content)
{
    std::ofstream out(outfile);
    out << content;
    return;
}

void writeFile(std::string outfile, std::string content)
{
    std::ofstream out(outfile);
    out << content;
    return;
}
