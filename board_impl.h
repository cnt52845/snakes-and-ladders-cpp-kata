#pragma once

#include "board.h"

class BoardImpl : public Board {
public:
    int move(int fromPosition, int steps) const override { return fromPosition + steps; }
};
