#pragma once

#include "players.h"

class PlayersImpl : public Players {
public:
    std::string getName() const override
    {
        if (!players.size()) {
            return "";
        }
        return players[currentPlayerIndex].name;
    }

    int getPosition() const override
    {
        if (!players.size()) {
            return 0;
        }
        return players[currentPlayerIndex].position;
    }

    void setPosition(int position) override
    {
        if (!players.size()) {
            return;
        }
        players[currentPlayerIndex].position = position;
    }

    void nextPlayer() override {}

    void addPlayer(std::string name) { players.emplace_back(Player{name, 0}); }

private:
    struct Player {
        std::string name{""};
        int         position{0};
    };
    std::vector<Player> players;
    std::size_t         currentPlayerIndex{0};
};
