#ifndef FORMATTER_HPP
#define FORMATTER_HPP
#include "../Command.hpp"

const int MENU_SPACING = 2;
const int COLUMN_WIDTH = 23;

void output_bold_text(std::string txt);
void printGlobalOptions();
void printGlobalUsage();
string getCommandName();

#endif