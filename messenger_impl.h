#pragma once

#include "messenger.h"

class MessengerImpl : public Messenger {
public:
    std::string playerPosition(std::string playerName, int position) const override
    {
        return "Player " + playerName + " is on square " + std::to_string(position);
    }

    std::string playerWins(std::string playerName) const override
    {
        return "Player " + playerName + " Wins!";
    }

    std::string gameOver() const override { return "Game over!"; }
};
