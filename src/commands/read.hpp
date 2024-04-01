#ifndef READ_HPP
#define READ_HPP
#include "../Command.hpp"

class ReadCommand : public Command
{
public:
    ReadCommand();
    void run(Args &ctx) override;
};
#endif