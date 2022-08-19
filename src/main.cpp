#include <iostream>
#include <string.h>

#include "fileHeaders.hpp"
#define VERSION "1.0.0"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        getHelp();
        return 0;
    }
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
        cout << "file-utils version: " << VERSION << endl;
    }

    if ((strcmp(argv[1], "read") == 0) || (strcmp(argv[1], "rd") == 0))
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

    if ((strcmp(argv[1], "copy") == 0) || (strcmp(argv[1], "cp") == 0))
    {
        writeFile(argv[2], argv[3]);
        return 1;
    }
}