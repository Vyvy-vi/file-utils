#include "help.hpp"
#include <iostream>
#include "../../include/styler.hh"
#include "../../include/json.hpp"
#include "formatter.hpp"
#include "../commands/read.hpp"
#include "../commands/copy.hpp"
#include "../commands/move.hpp"
#include "../commands/merge.hpp"
#include "../commands/version.hpp"
#include "../commands/delete.hpp"

using namespace styler;
using json = nlohmann::json;
using std::cout;
using std::endl;
using std::left;
using std::setfill;
using std::setw;
using std::string;

void getHelp()
{
    printGlobalUsage();
    printGlobalOptions();

    Command *cmds[] = {
        new ReadCommand(),
        new CopyCommand(),
        new DeleteCommand(),
        new MoveCommand(),
        new MergeCommand(),
        new VersionCommand()};

    output_bold_text("Commands");
    cout << ": " << endl;
    for (Command *cmd : cmds)
    {
        cout << setw(MENU_SPACING) << "";
        cout << setw(COLUMN_WIDTH) << left << cmd->name;
        cout << cmd->about << endl;
    }
    cout << endl;
}