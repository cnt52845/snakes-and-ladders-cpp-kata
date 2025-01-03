#pragma once

#include "messenger.h"

class MessengerImpl : public Messenger {
public:
    std::string playerPosition(std::string playerName, int position) const override
    {
        return "Player " + playerName + " is on square " + std::to_string(position);
    }
};
