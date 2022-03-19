#include <iostream>
#include <string.h>

#include "fileHeaders.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    string version = "1.0.0";
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0)
    {
        if (argv[2])
        {
            getHelp(argv[2]);
        }
        else
        {
            getHelp();
        }
        return 0;
    }
    else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
    {
        cout << "file-utils version: " << version << endl;
    }

    if (strcmp(argv[1], "read") == 0)
    {
        bool cond = (strcmp(argv[2], "-b") == 0) ? true : false;
        if (cond)
        {
            readFile(argv[3], cout, cond);
        }
        else
        {
            readFile(argv[2], cout);
        }
        return 1;
    }
}