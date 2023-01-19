#include <fstream>
#include "fileHeaders.hpp"

void copyFile(char *infile, char *outfile)
{
    std::ofstream out(outfile);
    readFile(infile, out);
    return;
}

void copyFile(std::string infile, std::string outfile)
{
    std::ofstream out(outfile);
    readFile(infile, out);
    return;
}
