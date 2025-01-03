#pragma once

#include <memory>
#include "players.h"
#include "board.h"
#include "messenger.h"

class SnakesAndLadders {
public:
    SnakesAndLadders(std::shared_ptr<Players> players, std::shared_ptr<Board> board,
                     std::shared_ptr<Messenger> messenger)
    {
    }
};
