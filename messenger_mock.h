#pragma once

#include <gmock/gmock.h>
#include "messenger.h"

class MessengerMock : public Messenger {
public:
    MOCK_METHOD(std::string, playerPosition, (std::string playerName, int position),
                (const override));
    MOCK_METHOD(std::string, playerWins, (std::string playerName), (const override));
    MOCK_METHOD(std::string, gameOver, (), (const override));
};
