#pragma once

#include "players.h"

class PlayersImpl : public Players {
public:
    std::string getName() const override { return name; }
    int         getPosition() const override { return position; }
    void        setPosition(int position) override
    {
        if (isPlayerAdded) {
            this->position = position;
        }
    }
    void nextPlayer() override {}
    void addPlayer(std::string name)
    {
        this->name    = name;
        isPlayerAdded = true;
    }

private:
    bool        isPlayerAdded{false};
    std::string name{""};
    int         position{0};
};
