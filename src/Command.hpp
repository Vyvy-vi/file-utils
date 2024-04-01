#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "../include/json.hpp"
#include "textUtils.hpp"
#include "vector"

using std::string;
using std::vector;
using json = nlohmann::json;

struct Args
{
    int argc;
    char **argv;
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
    void readFile(const std::string &infile, std::ostream &out, bool count);
    void readFile(const std::string &infile, std::ostream &out);
    void copyFile(const std::string &infile, const std::string &outfile);
    void writeFile(const std::string &outfile, const std::string &content);
    virtual void run(Args &ctx) = 0;
};
#endif