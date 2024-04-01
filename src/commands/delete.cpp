#include "delete.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::strcmp;

DeleteCommand::DeleteCommand()
{
    name = "delete";
    usage = "delete <filename1.ext> <filename2.ext> ...";
    about = "Deletes files";
    description = "This command can be used to delete files";
    aliases = NULL;
    vector<Option> options;
}

void DeleteCommand::run(Args &ctx)
{
    if (ctx.argc <= 2)
    {
        this->printHelp();
        return;
    }
    for (int i = 2; i < ctx.argc; i++)
    {
        if (remove(ctx.argv[i]) == 0)
            cout << "File " << ctx.argv[i] << " was deleted successfully..." << endl;
        else
        {
            cout << remove(ctx.argv[i]);
            cout << "Failed to remove file" << endl;
        }
    }
    return;
}
