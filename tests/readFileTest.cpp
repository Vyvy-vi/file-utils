#include <criterion/criterion.h>
#include <criterion/logging.h>

#include "../src/read.cpp"
#include <fstream>
#include <math.h>

using criterion::logging::error;
using criterion::logging::info;
using criterion::logging::warn;

std::string readLineSampleFile = "tests/inputs/readFileTestSample.txt";
std::string readLineStr = "Hello World";

std::string readMultiLineFileSampleFile = "tests/inputs/readMultiLineFileTestSample.txt";
std::string readMultiLineFileTestStr = "Hello World\nThis is text.\nstuff ...";

std::string readMultiParaFileSampleFile = "tests/inputs/readMultiParaFileTestSample.txt";
std::string readMultiParaFileTestStr = "\
This is a test. Does this work\n\
I hope this works.\n\n\
Yes it works\n\
stuff\n...\n\
abcd is read\n\
and that's that\n\n\
....";

std::ofstream fout;

void setupReadLine(void)
{
    fout.open(readLineSampleFile);
    fout << readLineStr << std::endl;
    fout.close();
}

void setupReadMultiLineFile(void)
{
    fout.open(readMultiLineFileSampleFile);
    fout << readMultiLineFileTestStr << std::endl;
    fout.close();
}

void setupReadMultiParaFile(void)
{
    fout.open(readMultiParaFileSampleFile);
    fout << readMultiParaFileTestStr << std::endl;
    fout.close();
}

void setup(void)
{
    setupReadLine();
    setupReadMultiLineFile();
    setupReadMultiParaFile();
}

TestSuite(readFile, .init = setup);

Test(readFile, readLine)
{
    std::string str;
    std::string TestOutputFile = "tests/inputs/readFileTestOutput1.txt";

    std::ofstream fout(TestOutputFile);
    readFile(readLineSampleFile, fout);

    std::ifstream in(TestOutputFile);
    getline(in, str);

    cr_assert(str == readLineStr);
}

Test(readFile, readMultiLineFile)
{
    std::string str = "";
    std::string TestOutputFile = "tests/inputs/readFileTestOutput2.txt";

    std::ofstream fout(TestOutputFile);
    readFile(readMultiLineFileSampleFile, fout);

    std::string tempStr;
    std::ifstream in(TestOutputFile);
    getline(in, str);

    while (getline(in, tempStr))
    {
        str += "\n";
        str += tempStr;
    }

    cr_assert(str == readMultiLineFileTestStr);
}

Test(readFile, readMultiParaFile)
{
    std::string str;
    std::string TestOutputFile = "tests/inputs/readFileTestOutput3.txt";

    fout.open(TestOutputFile);
    readFile(readMultiParaFileSampleFile, fout);
    fout.close();

    std::string tempStr;
    std::ifstream in(TestOutputFile);
    getline(in, str);
    while (getline(in, tempStr))
        str += ("\n" + tempStr);

    in.close();

    cr_assert(str == readMultiParaFileTestStr);
}

/*
Test(readFile, readEmptyFile) {
    std::string str;
    std::string TestSampleFile = "readFileTestSample.txt";
    std::string TestOutputFile = "readFileTestOutput.txt";
    std::ofstream fout;
    fout.open(TestSampleFile);
    fout<<"Hello World"<<std::endl;
    fout.close();

    fout.open(TestOutputFile);
    readFile(TestSampleFile, fout);
    fout.close();

    std::ifstream in(TestOutputFile);
    getline(in, str);

    cr_assert(str == "Hello World");
}
*/

std::string spaced(int num, int space)
{
    std::string response;
    for (int i = 0; i < space - log10(num) - 1; i++)
    {
        response += " ";
    }
    return response + std::to_string(num);
}

std::string numberedLines(std::string text)
{
    int lineCount = 1;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '\n')
            lineCount++;
    }

    std::string lines[lineCount];
    int lineCursor = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '\n')
            lineCursor += 1;
        else
            lines[lineCursor] += text[i];
    }

    std::string new_str;

    for (int i = 0; i < lineCount; i++)
    {
        new_str += spaced(i + 1, 6) + "  ";
        new_str += lines[i];
        if (i != lineCount - 1)
            new_str += '\n';
    }

    return new_str;
}

Test(readFile, numberLines)
{
    std::string str;
    std::string TestOutputFile = "tests/inputs/readFileTestOutput4.txt";

    fout.open(TestOutputFile);
    readFile(readMultiParaFileSampleFile, fout, true);
    fout.close();

    std::string tempStr;
    std::ifstream in(TestOutputFile);
    getline(in, str);
    while (getline(in, tempStr))
    {
        str += "\n";
        str += tempStr;
    }

    std::string numberedOutputSample = numberedLines(readMultiParaFileTestStr);

    cr_assert(str == numberedOutputSample);
}
/*
Test(readFile, numberOnlyNonBlankLines) {

}
*/