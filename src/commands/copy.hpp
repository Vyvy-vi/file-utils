#ifndef COPY_HPP
#define COPY_HPP
#include "../Command.hpp"

class CopyCommand : public Command
{
public:
    CopyCommand();
    void run(Args &ctx) override;
};
#endif