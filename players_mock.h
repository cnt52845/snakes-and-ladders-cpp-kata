#pragma once

#include <gmock/gmock.h>
#include "players.h"

class PlayersMock : public Players {
public:
    MOCK_METHOD(std::string, getName, (), (const override));
    MOCK_METHOD(int, getPosition, (), (const override));
    MOCK_METHOD(void, setPosition, (int position), (override));
    MOCK_METHOD(void, nextPlayer, (), (override));
};
