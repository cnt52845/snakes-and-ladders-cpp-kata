#pragma once

#include <gmock/gmock.h>
#include "board.h"

class BoardMock : public Board {
public:
    MOCK_METHOD(int, move, (int fromPosition, int steps), (const override));
    MOCK_METHOD(bool, isWon, (int position), (const override));
};
