#include <gtest/gtest.h>
#include "board_impl.h"

struct MoveTestParams {
    int fromPosition;
    int steps;
    int newPosition;
};

// Define the operator<< for MoveTestParams
std::ostream&
operator<<(std::ostream& os, const MoveTestParams& params)
{
    os << "fromPosition: " << params.fromPosition << ", "
       << "steps: " << params.steps << ", "
       << "newPosition: " << params.newPosition;
    return os;
}

class TestBoardImpl : public ::testing::TestWithParam<MoveTestParams> {
public:
    BoardImpl board;
};

TEST_P(TestBoardImpl, Move)
{
    const auto& params = GetParam();
    ASSERT_EQ(params.newPosition, board.move(params.fromPosition, params.steps));
}

INSTANTIATE_TEST_SUITE_P(
    MoveTests, TestBoardImpl,
    ::testing::Values(
        // Regular moves
        MoveTestParams{0, 0, 0}, MoveTestParams{0, 1, 1},
        // Ladders
        MoveTestParams{2, 0, 38}, MoveTestParams{7, 0, 14}, MoveTestParams{8, 0, 31},
        MoveTestParams{15, 0, 26}, MoveTestParams{21, 0, 42}, MoveTestParams{28, 0, 84},
        MoveTestParams{36, 0, 44}, MoveTestParams{51, 0, 67}, MoveTestParams{71, 0, 91},
        MoveTestParams{78, 0, 98}, MoveTestParams{87, 0, 94},
        // Snakes
        MoveTestParams{16, 0, 6}, MoveTestParams{46, 0, 25}, MoveTestParams{49, 0, 11},
        MoveTestParams{62, 0, 19}, MoveTestParams{64, 0, 60}, MoveTestParams{74, 0, 53},
        MoveTestParams{89, 0, 68}, MoveTestParams{92, 0, 88}, MoveTestParams{95, 0, 75},
        MoveTestParams{99, 0, 80},
        // Bounce back
        MoveTestParams{98, 5, 97}, MoveTestParams{98, 3, 80}));

TEST_F(TestBoardImpl, Given_isWon_called_When_position_is_not_100_Then_return_false)
{
    ASSERT_FALSE(board.isWon(99));
}

TEST_F(TestBoardImpl, Given_isWon_called_When_position_is_100_Then_return_true)
{
    ASSERT_TRUE(board.isWon(100));
}
