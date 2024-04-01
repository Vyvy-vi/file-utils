#include "merge.hpp"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::strcmp;

MergeCommand::MergeCommand()
{
    name = "merge";
    usage = "merge <filename1.ext> <filename2.ext> ...";
    about = "Merges contents of two or more files";
    description = "This command can be used to merge the contents of multiple files and print it to stdout or pipe the results to a new file.";
    aliases = NULL;
    vector<Option> options;
}

void MergeCommand::run(Args &ctx)
{
    std::ostringstream buf;
    for (int i = 2; i < ctx.argc; i++)
    {
        if (strcmp(ctx.argv[i], "-w") == 0 && ctx.argc <= i + 1)
        {
            cout << buf.str();
            cout << "Invalid filename for -w argument." << endl;
            this->printHelp();
            return;
        }
        else if (strcmp(ctx.argv[i], "-w") == 0)
        {
            this->writeFile(ctx.argv[i + 1], buf.str());
            return;
        }
        else
            this->readFile(ctx.argv[i], buf);
    }
    cout << buf.str();
}
