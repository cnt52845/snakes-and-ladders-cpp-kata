#include <gtest/gtest.h>

#include "messenger_impl.h"

class TestMessengerImpl : public ::testing::Test {
public:
    MessengerImpl messenger;
};

TEST_F(
    TestMessengerImpl,
    Given_playerPosition_called_When_playerName_is_1_and_position_is_5_Then_return_player_position)
{
    ASSERT_EQ("Player 1 is on square 5", messenger.playerPosition("1", 5));
}

TEST_F(TestMessengerImpl, Given_playerWins_called_When_playerName_is_1_Then_return_player_1_wins)
{
    ASSERT_EQ("Player 1 Wins!", messenger.playerWins("1"));
}

TEST_F(TestMessengerImpl, Given_gameOver_called_Then_return_game_over)
{
    ASSERT_EQ("Game over!", messenger.gameOver());
}
