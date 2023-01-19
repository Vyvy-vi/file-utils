#include <fstream>
#include "fileHeaders.hpp"
#include <iostream>

void writeFile(const std::string &outfile, const std::string &content)
{
    std::ofstream out(outfile);
    out << content;
    return;
}
