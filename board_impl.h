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
        return newPosition;
    }
};
