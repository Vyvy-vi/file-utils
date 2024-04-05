#include "../../include/styler.hh"
using styler::Style;

#include <iostream>
#include "../../include/json.hpp"
#include "formatter.hpp"
#include "../meta.hpp"

using namespace styler;
using json = nlohmann::json;
using std::cout;
using std::endl;
using std::left;
using std::setfill;
using std::setw;
using std::string;

void output_bold_text(std::string txt)
{
    std::cout << Style::Bold << txt << Style::Reset;
}

void printGlobalOptions()
{
    bool run;
    for (json::iterator it = meta["global-options"].begin(); it != meta["global-options"].end(); ++it)
    {
        if (it == meta["global-options"].begin())
        {
            output_bold_text("Global Options");
            cout << ": " << endl;
            run = true;
        }
        string option_identifier = (*it)["identifier"].get<string>();
        if ((*it)["aliases"].size() > 0)
            option_identifier = option_identifier + " (" + (*it)["aliases"][0].get<string>() + ")";

        cout << setw(MENU_SPACING) << "";
        cout << setw(COLUMN_WIDTH) << left << option_identifier;
        cout << (*it)["about"].get<string>() << endl;
    }
    if (run)
        cout << endl;
}

string getCommandName()
{
    return meta["command"].get<string>();
}

void printGlobalUsage()
{
    output_bold_text("Usage");
    cout << ": " << meta["command"].get<string>() << " " << meta["usage"].get<string>() << endl
         << endl;
    output_bold_text("Arguments");
    cout << ": " << endl;

    for (json::iterator it = meta["arguments"].begin(); it != meta["arguments"].end(); ++it)
    {
        cout << setw(MENU_SPACING) << "";
        cout << setw(COLUMN_WIDTH) << left << (*it)["identifier"].get<string>() << (*it)["about"].get<string>()
             << endl;
    }
    cout << endl;

    output_bold_text("Aliases");
    cout << ": ";
    for (json::iterator it = meta["aliases"].begin(); it != meta["aliases"].end(); ++it)
    {
        if (it != meta["aliases"].begin())
            cout << ", ";
        cout << it->get<string>();
    }
    cout << endl
         << endl;
}