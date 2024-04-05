#include <iostream>
#include <string.h>
#include <sstream>
#include "commands/read.hpp"
#include "commands/version.hpp"
#include "commands/copy.hpp"
#include "commands/move.hpp"
#include "commands/merge.hpp"
#include "commands/delete.hpp"
#include "utils/help.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    Command *cmd;
    if (argc < 2)
    {
        getHelp();
        return 1;
    }
    // if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0)
    // {
    //     if (argv[2])
    //     {
    //         getCommandHelp(argv[2]);
    //     }
    //     else
    //         getHelp();
    //     return 0;
    // }
    else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "version") == 0 || strcmp(argv[1], "--version") == 0)
    {
        cmd = new VersionCommand();
    }

    if ((strcmp(argv[1], "read") == 0) || (strcmp(argv[1], "rd") == 0))
        cmd = new ReadCommand();
    else if ((strcmp(argv[1], "copy") == 0) || (strcmp(argv[1], "cp") == 0))
        cmd = new CopyCommand();
    else if ((strcmp(argv[1], "move") == 0) || (strcmp(argv[1], "mv") == 0))
        cmd = new MoveCommand();
    else if ((strcmp(argv[1], "merge") == 0))
        cmd = new MergeCommand();
    else if ((strcmp(argv[1], "delete") == 0))
        cmd = new DeleteCommand();

    if (cmd != NULL)
    {
        cmd->run(*(new Args(argc, argv)));
        return 0;
    }
    else
    {
        return 1;
    }
}
