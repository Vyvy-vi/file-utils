#include "merge.hpp"

#ifndef MERGE_HPP
#define MERGE_HPP
MergeCommand::MergeCommand()
{
    name = "merge";
    usage = "merge <source_filename.ext> <destination_filename.ext>";
    about = "Merges contents of two or more files";
    description = "This command can be used to merge the contents of multiple files and print it to stdout or pipe the results to a new file";
}
void MergeCommand::run()
{
    this->printHelp();
}

#endif