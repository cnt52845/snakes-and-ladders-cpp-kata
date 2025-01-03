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
        board->isWon(players->getPosition());
        return messenger->gameOver();
    }

private:
    std::shared_ptr<Players>   players;
    std::shared_ptr<Board>     board;
    std::shared_ptr<Messenger> messenger;
};
