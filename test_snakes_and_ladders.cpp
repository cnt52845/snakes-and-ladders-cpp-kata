#include <memory>
#include <gtest/gtest.h>
#include "snakes_and_ladders.h"
#include "players_mock.h"
#include "board_mock.h"
#include "messenger_mock.h"

TEST(TestSnakesAndLaders, CanCreateInstance)
{
    std::shared_ptr<PlayersMock>      players   = std::make_shared<PlayersMock>();
    std::shared_ptr<BoardMock>        board     = std::make_shared<BoardMock>();
    std::shared_ptr<MessengerMock>    messenger = std::make_shared<MessengerMock>();
    std::shared_ptr<SnakesAndLadders> game =
        std::make_shared<SnakesAndLadders>(players, board, messenger);
}

TEST(TestSnakesAndLaders, CanPlay)
{
    std::shared_ptr<PlayersMock>      players   = std::make_shared<PlayersMock>();
    std::shared_ptr<BoardMock>        board     = std::make_shared<BoardMock>();
    std::shared_ptr<MessengerMock>    messenger = std::make_shared<MessengerMock>();
    std::shared_ptr<SnakesAndLadders> game =
        std::make_shared<SnakesAndLadders>(players, board, messenger);

    game->play(2, 3);
}
