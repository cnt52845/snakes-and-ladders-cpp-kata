#pragma once

#include <string>

class Messenger {
public:
    virtual std::string playerPosition(std::string playerName, int position) const = 0;
    virtual std::string playerWins(std::string playerName) const                   = 0;
};
