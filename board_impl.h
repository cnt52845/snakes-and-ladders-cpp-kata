#pragma once

#include <unordered_map>
#include "board.h"

class BoardImpl : public Board {
public:
    int move(int fromPosition, int steps) const override
    {
        int  newPosition = fromPosition + steps;
        auto it          = snakesAndLadders.find(newPosition);
        if (it != snakesAndLadders.end()) {
            newPosition = it->second;
        }
        return newPosition;
    }

private:
    std::unordered_map<int, int> snakesAndLadders{{2, 38}, {7, 14}};
};
