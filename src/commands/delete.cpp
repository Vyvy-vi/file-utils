#include "delete.hpp"

#ifndef DELETE_HPP
#define DELETE_HPP
DeleteCommand::DeleteCommand()
{
    name = "delete";
    usage = "delete <filename1.ext> <filename2.ext> ...";
    about = "Deletes files";
    description = "This command can be used to delete files";
}
void DeleteCommand::run()
{
    this->printHelp();
}

#endif