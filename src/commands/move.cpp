#include "move.hpp"

#ifndef Move_HPP
#define Move_HPP

MoveCommand::MoveCommand()
{
    name = "move";
    usage = "move <source_filename.ext> <destination_filename.ext>";
    about = "Move content of a file to a new file and delete source";
    description = "This command can be used to rename files";
    aliases = new string[1]{"mv"};
}
void MoveCommand::run()
{
    this->printHelp();
}

#endif