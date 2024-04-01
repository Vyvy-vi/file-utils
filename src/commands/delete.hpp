#ifndef DELETE_HPP
#define DELETE_HPP
#include "../Command.hpp"

class DeleteCommand : public Command
{
public:
    DeleteCommand();
    void run(Args &ctx) override;
};
#endif