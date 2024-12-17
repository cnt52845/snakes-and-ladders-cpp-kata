#pragma once

#include "players.h"

class PlayersImpl : public Players {
public:
    std::string getName() const override { return name; }
    int         getPosition() const override { return 0; }
    void        setPosition(int) override {}
    void        nextPlayer() override {}
    void        addPlayer(std::string name) { this->name = name; }

private:
    std::string name{""};
};
