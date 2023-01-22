#include <iostream>
#include <string.h>
#include <sstream>
#include "fileHeaders.hpp"
#define VERSION "1.0.0"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        getHelp();
        return 1;
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
    else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "version") == 0 || strcmp(argv[1], "--version") == 0)
    {
        cout << "file-utils version: " << VERSION << endl;
        return 0;
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
        return 0;
    }

    if ((strcmp(argv[1], "copy") == 0) || (strcmp(argv[1], "cp") == 0))
    {
        copyFile(argv[2], argv[3]);
        return 0;
    }

    if ((strcmp(argv[1], "merge") == 0))
    {
        std::ostringstream buf;
        for (int i = 2; i < argc; i++)
        {
            if (strcmp(argv[i], "-w") == 0 && argc <= i + 1)
            {
                cout << buf.str();
                cout << "Invalid filename for -w argument." << endl;
                getHelp(argv[1]);
                return 1;
            }
            else if (strcmp(argv[i], "-w") == 0)
            {
                writeFile(argv[i + 1], buf.str());
                return 0;
            }
            else
            {
                readFile(argv[i], buf);
            }
        }
        cout << buf.str();
        return 0;
    }

    if ((strcmp(argv[1], "delete") == 0))
    {
        if (argc <= 2)
        {
            getHelp("delete");
            return 1;
        }
        for (int i = 2; i < argc; i++)
        {
            if (remove(argv[i]) == 0)
                cout << "File " << argv[i] << " was deleted successfully..." << endl;
            else
            {
                cout << remove(argv[i]);
                cout << "Failed to remove file" << endl;
            }
        }
        return 0;
    }

    getHelp();
    return 1;
}