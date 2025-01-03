#pragma once

#include <memory>
#include "players.h"
#include "board.h"
#include "messenger.h"

class SnakesAndLadders {
public:
    SnakesAndLadders(std::shared_ptr<Players> players, std::shared_ptr<Board> board,
                     std::shared_ptr<Messenger> messenger)
        : players{players}, board{board}, messenger{messenger}
    {
    }

    std::string play(int dice1, int dice2)
    {
        int position = players->getPosition();
        if (board->isWon(position)) {
            return messenger->gameOver();
        }
        position = board->move(position, dice1 + dice2);
        players->setPosition(position);
        if (board->isWon(position)) {
            return messenger->playerWins(players->getName());
        }
        return messenger->playerPosition(players->getName(), position);
    }

private:
    std::shared_ptr<Players>   players;
    std::shared_ptr<Board>     board;
    std::shared_ptr<Messenger> messenger;
};
