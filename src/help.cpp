#include <iostream>
#include "fileHeaders.hpp"

void printHelpText() {
    std::string helpText = """Usage: file-utils <read> <path/to/file>\n\n\
Commands:\n\
    file-utils read [path-to-file]  # Reads a file\n\
Global Options:\n\
    --help, -h                      # Displays this help prompt\n\
    --version, -v                   # Shows version number\n\
""";
    std::cout<<helpText;
}