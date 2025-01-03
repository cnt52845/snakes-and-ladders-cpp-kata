#pragma once

#include <unordered_map>
#include "board.h"

class BoardImpl : public Board {
public:
    int move(int fromPosition, int steps) const override
    {
        int newPosition = fromPosition + steps;
        newPosition     = applyBounceBack(newPosition);
        newPosition     = applySnakesAndLadders(newPosition);
        return newPosition;
    }

    bool isWon(int position) const override { return position == BOARD_SIZE; }

private:
    int applyBounceBack(int newPosition) const
    {
        if (newPosition > BOARD_SIZE) {
            newPosition = BOARD_SIZE - (newPosition - BOARD_SIZE);
        }
        return newPosition;
    }

    int applySnakesAndLadders(int newPosition) const
    {
        auto it = snakesAndLadders.find(newPosition);
        if (it != snakesAndLadders.end()) {
            newPosition = it->second;
        }
        return newPosition;
    }

    static int constexpr BOARD_SIZE = 100;
    std::unordered_map<int, int> snakesAndLadders{// Ladders
                                                  {2, 38},
                                                  {7, 14},
                                                  {8, 31},
                                                  {15, 26},
                                                  {21, 42},
                                                  {28, 84},
                                                  {36, 44},
                                                  {51, 67},
                                                  {71, 91},
                                                  {78, 98},
                                                  {87, 94},

                                                  // Snakes
                                                  {16, 6},
                                                  {46, 25},
                                                  {49, 11},
                                                  {62, 19},
                                                  {64, 60},
                                                  {74, 53},
                                                  {89, 68},
                                                  {92, 88},
                                                  {95, 75},
                                                  {99, 80}};
};
