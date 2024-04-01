#include "read.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::strcmp;

ReadCommand::ReadCommand()
{
    name = "read";
    usage = "read <filename.ext>";
    about = "Reads a file and outputs contents to STDOUT";
    description = "This command can be used to read the contents of a file, and have them outputed to STDOUT or it can be piped to a new file";
    aliases = new string[2]{"rd", "cat"};
    vector<Option> options = {{"-b", "numbered output", "returnes numbered output"}};
}

void ReadCommand::run(Args &ctx)
{
    bool cond = (strcmp(ctx.argv[2], "-b") == 0) ? true : false;
    if (cond)
        this->readFile(ctx.argv[3], cout, cond);
    else
        this->readFile(ctx.argv[2], cout);
}
