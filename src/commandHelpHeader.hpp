// Command Help JSON Objects

#include "../include/json.hpp"

using json = nlohmann::json;

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
            "description": "",
            "options": []
        }
    }
)"_json;
