#include <gtest/gtest.h>
#include "players_impl.h"

class PlayersImplTest : public ::testing::Test {
public:
    PlayersImpl players;
};

TEST_F(PlayersImplTest, Given_getName_called_When_no_players_added_Then_return_empty_string)
{
    ASSERT_EQ("", players.getName());
}

TEST_F(PlayersImplTest, Given_getPosition_called_When_no_players_added_Then_return_zero)
{
    ASSERT_EQ(0, players.getPosition());
}

TEST_F(PlayersImplTest, Given_setPosition_called_When_no_players_added_Then_position_not_changed)
{
    players.setPosition(1);
    ASSERT_EQ(0, players.getPosition());
}
