#ifndef MOVE_HPP
#define MOVE_HPP
#include "../Command.hpp"

class MoveCommand : public Command
{
public:
    MoveCommand();
    void run(Args &ctx) override;
};
#endif