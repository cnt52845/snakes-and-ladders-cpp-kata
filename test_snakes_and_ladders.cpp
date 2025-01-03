#include <memory>
#include <gtest/gtest.h>
#include "snakes_and_ladders.h"
#include "players_mock.h"
#include "board_mock.h"
#include "messenger_mock.h"

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

TEST_F(TestSnakesAndLaders, CanPlay)
{
    game->play(2, 3);
}
