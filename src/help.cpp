#include <iostream>
#include "helpText.hpp"
#include "../include/styler.hh"
#include "../include/json.hpp"

using namespace styler;
using json = nlohmann::json;
using std::cout;
using std::endl;
using std::left;
using std::setfill;
using std::setw;
using std::string;

const int MENU_SPACING = 2;
const int COLUMN_WIDTH = 23;

void inline output_bold_text(string txt)
{
    cout << Style::Bold << txt << Style::Reset;
}

void printGlobalOptions()
{
    bool run;
    for (json::iterator it = helpTextJson["global-options"].begin(); it != helpTextJson["global-options"].end(); ++it)
    {
        if (it == helpTextJson["global-options"].begin())
        {
            output_bold_text("Global Options");
            cout << ": " << endl;
            run = true;
        }
        string option_identifier = (*it)["identifier"].get<string>();
        if ((*it)["aliases"].size() > 0)
        {
            option_identifier = option_identifier + " (" + (*it)["aliases"][0].get<string>() + ")";
        }

        cout << setw(MENU_SPACING) << "";
        cout << setw(COLUMN_WIDTH) << left << option_identifier;
        cout << (*it)["about"].get<string>() << endl;
    }
    if (run)
        cout << endl;
}

void getHelp()
{
    output_bold_text("Usage");
    cout << ": " << helpTextJson["command"].get<string>() << " " << helpTextJson["usage"].get<string>() << endl
         << endl;
    output_bold_text("Arguments");
    cout << ": " << endl;

    for (json::iterator it = helpTextJson["arguments"].begin(); it != helpTextJson["arguments"].end(); ++it)
    {
        cout << setw(MENU_SPACING) << "";
        cout << setw(COLUMN_WIDTH) << left << (*it)["identifier"].get<string>() << (*it)["about"].get<string>()
             << endl;
    }
    cout << endl;

    output_bold_text("Aliases");
    cout << ": ";
    for (json::iterator it = helpTextJson["aliases"].begin(); it != helpTextJson["aliases"].end(); ++it)
    {
        if (it != helpTextJson["aliases"].begin())
        {
            cout << ", ";
        };
        cout << it->get<string>();
    }
    cout << endl
         << endl;

    printGlobalOptions();

    output_bold_text("Commands");
    cout << ": " << endl;
    for (json::iterator it = commandsHelpJson.begin(); it != commandsHelpJson.end(); ++it)
    {
        cout << setw(MENU_SPACING) << "";
        cout << setw(COLUMN_WIDTH) << left << (*it)["name"].get<string>();
        cout << (*it)["about"].get<string>() << endl;
    }
    cout << endl;
}

void getHelp(string cmd)
{
    auto find_cmd = commandsHelpJson.find(cmd);
    if (find_cmd == commandsHelpJson.end())
    {
        getHelp();
    }
    else
    {
        output_bold_text("Usage");
        cout << ": " << helpTextJson["command"].get<string>() << " " << commandsHelpJson[cmd]["usage"].get<string>() << endl
             << endl;

        bool run;
        for (json::iterator it = commandsHelpJson[cmd]["options"].begin(); it != commandsHelpJson[cmd]["options"].end(); ++it)
        {
            if (it == commandsHelpJson[cmd]["options"].begin())
            {
                output_bold_text("Options");
                cout << ": " << endl;
                run = true;
            }
            string option_identifier = (*it)["identifier"].get<string>();
            if ((*it)["aliases"].size() > 0)
            {
                option_identifier = option_identifier + " (" + (*it)["aliases"][0].get<string>() + ")";
            }

            cout << setw(MENU_SPACING) << "";
            cout << setw(COLUMN_WIDTH) << left << option_identifier;
            cout << (*it)["about"].get<string>() << endl;
        }
        if (run)
        {
            cout << endl;
        }
        printGlobalOptions();
        if ((commandsHelpJson[cmd].find("description") != commandsHelpJson[cmd].end()) && commandsHelpJson[cmd]["description"] != "")
        {
            output_bold_text("Description");
            cout << ": " << endl;

            cout << commandsHelpJson[cmd]["description"].get<string>() << endl
                 << endl;
        }
    }
}
