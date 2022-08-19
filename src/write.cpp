#include <fstream>
#include "fileHeaders.hpp"

void writeFile(char *infile, char *outfile)
{
    std::ofstream out(outfile);
    readFile(infile, out);
    return;
}

void writeFile(std::string infile, std::string outfile)
{
    std::ofstream out(outfile);
    readFile(infile, out);
    return;
}
