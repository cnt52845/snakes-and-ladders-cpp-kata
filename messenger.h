#pragma once

#include <string>

class Messenger {
public:
    virtual std::string playerPosition(std::string playerName, int position) const = 0;
};
