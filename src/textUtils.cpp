#include "../include/styler.hh"
using styler::Style;
void output_bold_text(std::string txt)
{
    std::cout << Style::Bold << txt << Style::Reset;
}