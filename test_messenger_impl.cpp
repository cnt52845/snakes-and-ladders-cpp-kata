#include <gtest/gtest.h>

#include "messenger_impl.h"

TEST(TestMessengerImpl, CanCreateInstance)
{
    MessengerImpl messenger;
}

TEST(TestMessengerImpl,
     Given_playerPosition_called_When_playerName_is_1_and_position_is_5_Then_return_player_position)
{
    MessengerImpl messenger;
    ASSERT_EQ("Player 1 is on square 5", messenger.playerPosition("1", 5));
}
