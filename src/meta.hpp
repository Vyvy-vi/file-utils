// Command Help JSON Objects
#ifndef META_HPP
#define META_ HPP
#include <iostream>
#include "../include/json.hpp"
using json = nlohmann::json;

auto meta = R"(
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
#endif