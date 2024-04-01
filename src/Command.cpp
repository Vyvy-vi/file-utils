#include "../include/json.hpp"
#include "../include/styler.hh"
#include "helpMeta.hpp"
#include "Command.hpp"
#include <iostream>
#include "vector"
#include <sstream>
#include "textUtils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using std::endl;
using std::left;
using std::setfill;
using std::setw;
using std::string;

const int MENU_SPACING = 2;
const int COLUMN_WIDTH = 23;

using std::cout;
using std::endl;
using std::string;
using json = nlohmann::json;

Args::Args(int argc, char *argv[])
{
    this->argc = argc;
    this->argv = argv;
}

Option::Option(
    string identifier,
    string name,
    string about) : Option::Option(identifier, name, about, "")
{
}

Option::Option(string identifier, string name, string about, string alias)
{
    this->identifier = identifier;
    this->name = name;
    this->about = about;
    this->alias = alias;
}

void Command::printHelp()
{
    output_bold_text("Usage");
    cout << ": " << helpMeta["command"].get<string>() << " " << usage << endl
         << endl;

    if (!options.empty())
    {
        output_bold_text("Options");
        cout << ": " << endl;
        for (auto &option : options)
        {
            std::stringstream option_identifier;
            option_identifier << option.identifier;
            if (!option.alias.empty())
            {
                option_identifier << " (" << option.alias << ")";
            }

            cout << setw(MENU_SPACING) << "";
            cout << setw(COLUMN_WIDTH) << left << option_identifier.str();
            cout << option.about << endl;
        }
        cout << endl;
    }

    printGlobalOptions();

    output_bold_text("Description");
    cout << ": " << endl;

    cout << description << endl
         << endl;

    if (aliases != nullptr)
    {
        output_bold_text("Aliases");
        cout << ": ";

        std::stringstream alias_str;
        alias_str << *aliases;
        for (string *alias = ++aliases; *alias != ""; ++alias)
        {
            alias_str << ", " << *alias;
        }

        cout << alias_str.str() << endl
             << endl;
    }
}

void Command::readFile(const std::string &infile, std::ostream &out)
{
    Command::readFile(infile, out, false);
}

void Command::readFile(const std::string &infile, std::ostream &out, bool count)
{
    int counter = 0;
    std::string str;
    std::ifstream in(infile);

    while (getline(in, str))
    {
        if (count)
            out << std::setw(6) << ++counter << "  ";
        out << str << std::endl;
    }
}

void Command::writeFile(const std::string &outfile, const std::string &content)
{
    std::ofstream out(outfile);
    out << content;
}

void Command::copyFile(const std::string &infile, const std::string &outfile)
{
    std::ofstream out(outfile);
    readFile(infile, out);
}
