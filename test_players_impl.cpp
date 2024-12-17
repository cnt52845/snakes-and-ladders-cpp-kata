#include <gtest/gtest.h>
#include "players_impl.h"

TEST(PlayersImpl, CanCreateInstance)
{
    PlayersImpl players;
}

TEST(PlayersImpl, Given_getName_called_When_no_players_added_Then_return_empty_string)
{
    PlayersImpl players;
    ASSERT_EQ("", players.getName());
}
