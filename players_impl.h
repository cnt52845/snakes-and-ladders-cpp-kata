#pragma once

#include "players.h"

class PlayersImpl : public Players {
public:
    void        addPlayer(std::string name) override {}
    std::string getName() const override { return "1"; }
};
