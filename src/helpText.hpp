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
        "version": {
            "name": "version",
            "usage": "version",
            "aliases": [],
            "about": "Returns the version of the tool",
            "description": "",
            "options": []
        },
        "read": {
            "name": "read",
            "usage": "read <filename.ext>",
            "aliases": ["rd"],
            "about": "Reads a file and outputs contents to STDOUT",
            "description": "This command can be used to read the contents of a file, and have them outputed to STDOUT or it can be piped to a new file",
            "options" : [{
                "identifier": "-b",
                "name": "numbered output",
                "aliases": [],
                "about": "Returns numbered output"
            }]
        },
        "copy": {
            "name": "copy",
            "usage": "copy <source_filename.ext> <destination_filename.ext>",
            "aliases": ["cp"],
            "about": "Copies the contents from source file to destination file",
            "description": "This command can be used to copy the contents of a file to a pre-existing or new file",
            "options" : []
        },
        "move": {
            "name": "move",
            "usage": "move <source_filename.ext> <destination_filename.ext>",
            "aliases": ["mv"],
            "about": "Move content of a file to a new file and delete source",
            "description": "This command can be used to rename files",
            "options": []
        },
        "merge": {
            "name": "merge",
            "usage": "merge <filename1.ext> <filename2.ext> ...",
            "aliases": [],
            "about": "Merges contents of two or more files",
            "description" : "This command can be used to merge the contents of multiple files and print it to stdout or pipe the results to a new file",
            "options" : []
        },
        "delete": {
            "name": "delete",
            "usage": "delete <filename1.ext> <filename2.ext> ...",
            "aliases": [""],
            "about": "Deletes files",
            "description": "This command can be used to delete files",
            "options": []
        }
    }
)"_json;