#include <memory>
#include <gtest/gtest.h>
#include "snakes_and_ladders.h"
#include "players_impl.h"
#include "players_mock.h"
#include "board_impl.h"
#include "board_mock.h"
#include "messenger_impl.h"
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

TEST_F(TestSnakesAndLaders, Given_play_called_When_next_step_wins_Then_return_player_wins)
{
    const int         dice1           = 3;
    const int         dice2           = 2;
    const int         currentPosition = 95;
    const int         newPosition     = 100;
    const std::string playerName      = "1";
    const std::string returnedResult  = "Player 1 Wins!";

    EXPECT_CALL(*players, getPosition()).WillOnce(Return(currentPosition));
    EXPECT_CALL(*board, isWon(currentPosition)).WillOnce(Return(false));
    EXPECT_CALL(*board, move(currentPosition, dice1 + dice2)).WillOnce(Return(newPosition));
    EXPECT_CALL(*players, setPosition(newPosition));
    EXPECT_CALL(*board, isWon(newPosition)).WillOnce(Return(true));
    EXPECT_CALL(*players, getName()).WillOnce(Return(playerName));
    EXPECT_CALL(*messenger, playerWins(playerName)).WillOnce(Return(returnedResult));

    ASSERT_EQ(returnedResult, game->play(dice1, dice2));
}

TEST_F(
    TestSnakesAndLaders,
    Given_play_called_When_roll_double_and_next_step_does_not_win_Then_return_player_position_and_roll_again)
{
    const int         dice1           = 3;
    const int         dice2           = 3;
    const int         currentPosition = 50;
    const int         newPosition     = 56;
    const std::string playerName      = "1";
    const std::string returnedResult  = "Player 1 is on square 56";

    EXPECT_CALL(*players, getPosition()).WillOnce(Return(currentPosition));
    EXPECT_CALL(*board, isWon(currentPosition)).WillOnce(Return(false));
    EXPECT_CALL(*board, move(currentPosition, dice1 + dice2)).WillOnce(Return(newPosition));
    EXPECT_CALL(*players, setPosition(newPosition));
    EXPECT_CALL(*board, isWon(newPosition)).WillOnce(Return(false));
    EXPECT_CALL(*players, getName()).WillOnce(Return(playerName));
    EXPECT_CALL(*messenger, playerPosition(playerName, newPosition))
        .WillOnce(Return(returnedResult));
    EXPECT_CALL(*players, nextPlayer()).Times(0);

    ASSERT_EQ(returnedResult, game->play(dice1, dice2));
}

TEST_F(
    TestSnakesAndLaders,
    Given_play_called_When_roll_different_and_next_step_does_not_win_Then_return_player_position_and_switch_player)
{
    const int         dice1           = 3;
    const int         dice2           = 2;
    const int         currentPosition = 50;
    const int         newPosition     = 55;
    const std::string playerName      = "1";
    const std::string returnedResult  = "Player 1 is on square 55";

    EXPECT_CALL(*players, getPosition()).WillOnce(Return(currentPosition));
    EXPECT_CALL(*board, isWon(currentPosition)).WillOnce(Return(false));
    EXPECT_CALL(*board, move(currentPosition, dice1 + dice2)).WillOnce(Return(newPosition));
    EXPECT_CALL(*players, setPosition(newPosition));
    EXPECT_CALL(*board, isWon(newPosition)).WillOnce(Return(false));
    EXPECT_CALL(*players, getName()).WillOnce(Return(playerName));
    EXPECT_CALL(*messenger, playerPosition(playerName, newPosition))
        .WillOnce(Return(returnedResult));
    EXPECT_CALL(*players, nextPlayer());

    ASSERT_EQ(returnedResult, game->play(dice1, dice2));
}

class TestSnakesAndLadersIntegration : public ::testing::Test {
public:
    std::shared_ptr<PlayersImpl>      players;
    std::shared_ptr<BoardImpl>        board;
    std::shared_ptr<MessengerImpl>    messenger;
    std::shared_ptr<SnakesAndLadders> game;

    void SetUp() override
    {
        messenger = std::make_shared<MessengerImpl>();
        board     = std::make_shared<BoardImpl>();
        players   = std::make_shared<PlayersImpl>();
        players->addPlayer("1");
        players->addPlayer("2");
        game = std::make_shared<SnakesAndLadders>(players, board, messenger);
    }

    void TearDown() override
    {
        game.reset();
        players.reset();
        board.reset();
        messenger.reset();
    }
};

TEST_F(TestSnakesAndLadersIntegration, PlayerOneWins)
{
    ASSERT_EQ("Player 1 is on square 14", game->play(4, 3));
    ASSERT_EQ("Player 2 is on square 12", game->play(6, 6));
    ASSERT_EQ("Player 2 is on square 26", game->play(1, 2));
    ASSERT_EQ("Player 1 is on square 26", game->play(6, 6));
    ASSERT_EQ("Player 1 is on square 84", game->play(1, 1));
    ASSERT_EQ("Player 1 is on square 96", game->play(6, 6));
    ASSERT_EQ("Player 1 is on square 98", game->play(3, 3)); // bounce back
    ASSERT_EQ("Player 1 Wins!", game->play(1, 1));
    ASSERT_EQ("Game over!", game->play(1, 2));
}

TEST_F(TestSnakesAndLadersIntegration, PlayerTwoWins)
{
    ASSERT_EQ("Player 1 is on square 14", game->play(4, 3));
    ASSERT_EQ("Player 2 is on square 12", game->play(6, 6));
    ASSERT_EQ("Player 2 is on square 24", game->play(6, 6));
    ASSERT_EQ("Player 2 is on square 84", game->play(2, 2));
    ASSERT_EQ("Player 2 is on square 96", game->play(6, 6));
    ASSERT_EQ("Player 2 Wins!", game->play(1, 3));
    ASSERT_EQ("Game over!", game->play(5, 4));
}
