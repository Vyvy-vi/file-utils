#include <criterion/criterion.h>
#include "../src/readFile.cpp"
#include <fstream>

Test(readFileTest, passing) {
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