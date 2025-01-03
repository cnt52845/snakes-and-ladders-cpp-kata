#include <gtest/gtest.h>
#include "board_impl.h"

TEST(TestBoardImpl, CanCreateInstance)
{
    BoardImpl board;
}

TEST(TestBoardImpl, Given_move_called_When_steps_0_Then_return_original_position)
{
    BoardImpl board;
    ASSERT_EQ(0, board.move(0, 0));
}
