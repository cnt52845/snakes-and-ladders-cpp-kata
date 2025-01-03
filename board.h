#pragma once

class Board {
public:
    virtual int  move(int fromPosition, int steps) const = 0;
    virtual bool isWon(int position) const               = 0;
};
