#include "copy.hpp"

#ifndef COPY_HPP
#define COPY_HPP
CopyCommand::CopyCommand()
{
    name = "copy";
    usage = "copy <source_filename.ext> <destination_filename.ext>";
    about = "Copies the contents from source file to destination file";
    description = "This command can be used to copy the contents of a file to a pre-existing or new file";
    aliases = new string[1]{"cp"};
}
void CopyCommand::run()
{
    this->printHelp();
}

#endif