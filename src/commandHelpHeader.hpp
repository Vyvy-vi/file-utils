// Command Help JSON Objects
#include <iostream>
#include "../include/json.hpp"
using json = nlohmann::json;
using std::cout;
using std::endl;
auto helpTextJson = R"(
    {
        "command": "file-utils",
        "aliases": ["fu"],
        "about": "A file utility CLI tool",
        "usage": "<command> [<arg1>] ... [<argN>]",
        "arguments": [
            {
                "identifier": "<command>",
                "about": "The command to execute"
            },
            {
                "identifier": "<arg>",
                "about": "The arguments of the command"
            }
        ],
        "global-options": [
            {
                "identifier": "-h",
                "name": "command help",
                "aliases": ["--help"],
                "about": "Displays this help message"
            },
            {
                "identifier": "-q",
                "name": "quiet mode",
                "aliases": ["--quiet"],
                "about": "Doesn't ouput messages"
            },
            {
                "identifier": "-v",
                "name": "project version",
                "aliases": ["--version"],
                "about": "Displays the application's version"
            },
            {
                "identifier": "--ansi",
                "name": "ANSI mode",
                "aliases": [],
                "about": "Force ANSI output"
            },
            {
                "identifier": "--no-ansi",
                "name": "non-ANSI mode",
                "aliases": [],
                "about": "Disable ANSI output"
            }
        ]
    }
)"_json;
auto commandsHelpJson = R"(
    {
        "help": {
            "name": "help",
            "usage": "help [<command>]",
            "aliases": [],
            "about": "Shows this help message.",
            "description": "",
            "options": []
        },
        "read": {
            "name": "read",
            "usage": "read <filename.ext>",
            "aliases": [],
            "about": "Reads a file and outputs contents to STDOUT",
            "description": "This command can be to read the contents of a file, and have them outputed to STDOUT or it can be piped to a new file",
            "options" : []
        }
    }
)"_json;