#include <fstream>
#include "fileHeaders.hpp"

void copyFile(const std::string &infile, const std::string &outfile)
{
    std::ofstream out(outfile);
    readFile(infile, out);
    return;
}
