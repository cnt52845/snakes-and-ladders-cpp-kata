#include <memory>
#include <gtest/gtest.h>
#include "snakes_and_ladders.h"
#include "players_mock.h"
#include "board_mock.h"
#include "messenger_mock.h"

using ::testing::Return;

class TestSnakesAndLaders : public ::testing::Test {
public:
    std::shared_ptr<PlayersMock>      players;
    std::shared_ptr<BoardMock>        board;
    std::shared_ptr<MessengerMock>    messenger;
    std::shared_ptr<SnakesAndLadders> game;

    void SetUp() override
    {
        players   = std::make_shared<PlayersMock>();
        board     = std::make_shared<BoardMock>();
        messenger = std::make_shared<MessengerMock>();
        game      = std::make_shared<SnakesAndLadders>(players, board, messenger);
    }
};

TEST_F(TestSnakesAndLaders, Given_play_called_When_game_already_won_Then_return_game_over)
{
    const int         dice1           = 2;
    const int         dice2           = 3;
    const int         currentPosition = 100;
    const std::string returnedResult  = "Game over!";

    EXPECT_CALL(*players, getPosition()).WillOnce(Return(currentPosition));
    EXPECT_CALL(*board, isWon(currentPosition)).WillOnce(Return(true));
    EXPECT_CALL(*messenger, gameOver()).WillOnce(Return(returnedResult));

    ASSERT_EQ(returnedResult, game->play(dice1, dice2));
}
