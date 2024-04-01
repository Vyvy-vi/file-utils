#ifndef VERSION_HPP
#define VERSION_HPP
#include "../Command.hpp"
#include <iostream>

class VersionCommand : public Command
{
public:
    VersionCommand();
    void run(Args &ctx) override;
};
#endif