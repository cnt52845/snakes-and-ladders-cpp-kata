#pragma once

#include "players.h"

class PlayersImpl : public Players {
public:
    std::string getName() const override { return player.name; }
    int         getPosition() const override { return player.position; }
    void        setPosition(int position) override
    {
        if (isPlayerAdded) {
            player.position = position;
        }
    }
    void nextPlayer() override {}
    void addPlayer(std::string name)
    {
        player.name   = name;
        isPlayerAdded = true;
    }

private:
    struct Player {
        std::string name{""};
        int         position{0};
    };
    Player player;
    bool   isPlayerAdded{false};
};
