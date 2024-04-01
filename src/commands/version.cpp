#include "version.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#define VERSION "1.0.0"

using std::cout;
using std::endl;

VersionCommand::VersionCommand()
{
    name = "version";
    usage = "version";
    about = "Returns version of project";
    description = "This command can be used to get version of the tool";
    aliases = NULL;
    vector<Option> options;
}

void VersionCommand::run(Args &ctx)
{
    cout << "File Utils - " << VERSION << endl;
}