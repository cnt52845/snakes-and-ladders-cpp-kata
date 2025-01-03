#include <gtest/gtest.h>
#include "board_impl.h"

class TestBoardImpl : public ::testing::Test {
public:
    BoardImpl board;
};

TEST_F(TestBoardImpl, Given_move_called_When_steps_0_Then_return_original_position)
{
    ASSERT_EQ(0, board.move(0, 0));
}

TEST_F(TestBoardImpl, Given_move_called_When_steps_1_Then_return_position_plus_steps)
{
    ASSERT_EQ(1, board.move(0, 1));
}
