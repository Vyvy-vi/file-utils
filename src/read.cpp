#include <fstream>
#include <iostream>
#include "fileHeaders.hpp"
#include "../include/json.hpp"

void readFile(char *infile, std::ostream &out)
{
    readFile(infile, out, false);
}

void readFile(std::string infile, std::ostream &out)
{
    readFile(infile, out, false);
}

void readFile(char *infile, std::ostream &out, bool count)
{
    int counter = 0;
    std::string str;
    std::ifstream in(infile);

    while (getline(in, str))
    {
        if (count)
        {
            out << std::setw(6) << ++counter << "  ";
        }
        out << str << std::endl;
    }
    return;
}

void readFile(std::string infile, std::ostream &out, bool count)
{
    int counter = 0;
    std::string str;
    std::ifstream in(infile);

    while (getline(in, str))
    {
        if (count)
        {
            out << std::setw(6) << ++counter << "  ";
        }
        out << str << std::endl;
    }
    return;
}