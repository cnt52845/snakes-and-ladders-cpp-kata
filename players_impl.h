#pragma once

#include "players.h"

class PlayersImpl : public Players {
public:
    std::string getName() const override { return ""; }
    int         getPosition() const override { return 0; }
};
