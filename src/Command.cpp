#include "../include/json.hpp"
#include "../include/styler.hh"
#include "helpMeta.hpp"
#include "Command.hpp"
#include <iostream>
#include "vector"
#include <sstream>
#include "textUtils.hpp"

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

#ifndef COMMAND_HPP
#define COMMAND_HPP
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

#endif