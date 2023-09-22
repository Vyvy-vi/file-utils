#include "../Command.hpp"

class ReadCommand : public Command
{
public:
    ReadCommand();
    void run(Context &ctx) override;
};