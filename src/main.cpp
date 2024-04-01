#include <iostream>
#include <string.h>
#include <sstream>
#include "fileHeaders.hpp"
#include "commands/read.hpp"
#include "commands/version.hpp"
#include "commands/copy.hpp"
#include "commands/move.hpp"
#include "commands/merge.hpp"
#include "commands/delete.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // string aliases[] = {"rd", "cat"};
    // vector<Option> options = {{"-b", "numbered output", "returnes numbered output"}};
    // Command *read = new Command(
    //     "read",
    //     "file-utils read <filename.ext>",
    //     "Reads a file and outputs contents to STDOUT",
    //     "This command can be used to read the contents of a file, and have them outputed to STDOUT or it can be piped to a new file",
    //     aliases,
    //    options);

    if (argc < 2)
    {
        getHelp();
        return 1;
    }
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0)
    {
        if (argv[2])
            getCommandHelp(argv[2]);
        else
            getHelp();
        return 0;
    }
    else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "version") == 0 || strcmp(argv[1], "--version") == 0)
    {
        VersionCommand *cmd = new VersionCommand();
        Args *args = new Args(argc, argv);
        cmd->run(*args);
        return 0;
    }

    if ((strcmp(argv[1], "read") == 0) || (strcmp(argv[1], "rd") == 0))
    {
        ReadCommand *cmd = new ReadCommand();
        Args *args = new Args(argc, argv);
        cmd->run(*args);
        return 0;
    }

    if ((strcmp(argv[1], "copy") == 0) || (strcmp(argv[1], "cp") == 0))
    {
        CopyCommand *cmd = new CopyCommand();
        Args *args = new Args(argc, argv);
        cmd->run(*args);
        return 0;
    }

    if ((strcmp(argv[1], "move") == 0) || (strcmp(argv[1], "mv") == 0))
    {
        MoveCommand *cmd = new MoveCommand();
        Args *args = new Args(argc, argv);
        cmd->run(*args);
        return 0;
    }

    if ((strcmp(argv[1], "merge") == 0))
    {
        MergeCommand *cmd = new MergeCommand();
        Args *args = new Args(argc, argv);
        cmd->run(*args);
        return 0;
    }

    if ((strcmp(argv[1], "delete") == 0))
    {
        DeleteCommand *cmd = new DeleteCommand();
        Args *args = new Args(argc, argv);
        cmd->run(*args);
        return 0;
    }

    return 1;
}
