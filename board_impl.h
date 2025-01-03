#pragma once

#include "board.h"

class BoardImpl : public Board {
public:
    int move(int fromPosition, int steps) const override
    {
        int newPosition = fromPosition + steps;
        if (newPosition == 2) {
            newPosition = 38;
        }
        else if (newPosition == 7) {
            newPosition = 14;
        }
        return newPosition;
    }
};
