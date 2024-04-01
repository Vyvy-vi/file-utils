#include "copy.hpp"

CopyCommand::CopyCommand()
{
    name = "copy";
    usage = "copy <filename1.ext> <filename2.ext>";
    about = "Copys contents from one file to another";
    description = "This command can be used to copy the contents of a file to a pre-existing or new file.";
    aliases = new string[1]{"cp"};
    vector<Option> options;
}

void CopyCommand::run(Args &ctx)
{
    this->copyFile(ctx.argv[2], ctx.argv[3]);
}
