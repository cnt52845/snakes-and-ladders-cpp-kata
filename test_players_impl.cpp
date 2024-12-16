#include <gtest/gtest.h>
#include "players_impl.h"

TEST(PlayersImpl, CanCreateInstance)
{
    PlayersImpl players;
}

TEST(PlayersImpl, CanAddPlayer)
{
    PlayersImpl players;
    players.addPlayer("1");
}
