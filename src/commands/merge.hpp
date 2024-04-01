#ifndef MERGE_HPP
#define MERGE_HPP
#include "../Command.hpp"

class MergeCommand : public Command
{
public:
    MergeCommand();
    void run(Args &ctx) override;
};
#endif