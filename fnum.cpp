#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

string spaced(int num, int space)
{
    string response;
    for (int i = 0; i < space - log10(num) - 1; i++)
    {
        response += " ";
    }
    return response + to_string(num);
}

int main()
{
    string str = "\
This is a test. Does this work\n\
I hope this works.\n\n\
Yes it works\n\
stuff\n...\n\
abcd is read\n\
and that's that\n\n\
....";

    int lineCount = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '\n')
        {
            lineCount++;
        }
    }

    string lines[lineCount];
    int lineCursor = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '\n')
        {
            lineCursor+=1;
        }
        else {
            lines[lineCursor] += str[i];
        }
    }

    string new_str;

    for (int i = 0; i < lineCount; i++)
    {
        new_str += spaced(i + 1, 6) + "  ";
        new_str += lines[i];
        if (i != lineCount - 1)
            new_str += '\n';
    }

    cout << new_str << endl;
}
