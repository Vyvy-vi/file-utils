#include "read.hpp"

#ifndef READ_HPP
#define READ_HPP
ReadCommand::ReadCommand()
{
    name = "read";
    usage = "read <filename.ext>";
    about = "Reads a file and outputs contents to STDOUT";
    description = "This command can be used to read the contents of a file, and have them outputed to STDOUT or it can be piped to a new file";
    aliases = new string[2]{"rd", "cat"};
    vector<Option> options = {{"-b", "numbered output", "returnes numbered output"}};
}
void ReadCommand::run()
{
    this->printHelp();
}

#endif