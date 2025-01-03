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

INSTANTIATE_TEST_SUITE_P(MoveTests, TestBoardImpl,
                         ::testing::Values(
                             // Regular moves
                             MoveTestParams{0, 0, 0}, MoveTestParams{0, 1, 1},
                             // Snakes
                             MoveTestParams{2, 0, 38}, MoveTestParams{7, 0, 14}));
