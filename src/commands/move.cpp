#include "move.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::strcmp;

MoveCommand::MoveCommand()
{
    name = "move";
    usage = "move <source_filename.ext> <destination_filename.ext>";
    about = "Move content of a file to a new file and delete source";
    description = "This command can be used to rename files and move files into different locations.";
    aliases = new string[1]{"mv"};
    vector<Option> options;
}

void MoveCommand::run(Args &ctx)
{
    this->copyFile(ctx.argv[2], ctx.argv[3]);
    if (remove(ctx.argv[2]) != 0)
    {
        cout << "Failed to remove file, copied instead..." << endl;
    }
}
