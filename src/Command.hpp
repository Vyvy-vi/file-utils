#include "../include/json.hpp"
#include "textUtils.hpp"
#include "vector"

using std::string;
using std::vector;
using json = nlohmann::json;

struct Args
{
    int argc;
    char *argv;
    Args(int argc, char *argv[]);
};

class Option
{
public:
    string identifier;
    string name;
    string alias;
    string about;

    Option(string identifier, string name, string about);
    Option(string identifier, string name, string about, string alias);
};

class Command
{
public:
    string name;
    string usage;
    string about;
    string description;
    string *aliases;
    vector<Option> options;

    void printHelp();
    virtual void run(Args &ctx) = 0;
};