#include <gtest/gtest.h>
#include "players_impl.h"

class TestPlayersImplNoPlayers : public ::testing::Test {
public:
    PlayersImpl players;
};

TEST_F(TestPlayersImplNoPlayers,
       Given_getName_called_When_no_players_added_Then_return_empty_string)
{
    ASSERT_EQ("", players.getName());
}

TEST_F(TestPlayersImplNoPlayers, Given_getPosition_called_When_no_players_added_Then_return_zero)
{
    ASSERT_EQ(0, players.getPosition());
}

TEST_F(TestPlayersImplNoPlayers,
       Given_setPosition_called_When_no_players_added_Then_position_not_changed)
{
    players.setPosition(1);
    ASSERT_EQ(0, players.getPosition());
}

TEST_F(TestPlayersImplNoPlayers,
       Given_nextPlayer_called_When_no_players_added_Then_player_not_changed)
{
    players.nextPlayer();
    ASSERT_EQ("", players.getName());
    ASSERT_EQ(0, players.getPosition());
}

class TestPlayersImplOnePlayer : public TestPlayersImplNoPlayers {
public:
    void SetUp() override { players.addPlayer("1"); }
};

TEST_F(TestPlayersImplOnePlayer, Given_getName_called_When_one_player_added_Then_return_name)
{
    ASSERT_EQ("1", players.getName());
}

TEST_F(TestPlayersImplOnePlayer, Given_getPosition_called_When_one_player_added_Then_return_zero)
{
    ASSERT_EQ(0, players.getPosition());
}

TEST_F(TestPlayersImplOnePlayer,
       Given_setPosition_called_When_one_player_added_Then_position_changed)
{
    players.setPosition(1);
    ASSERT_EQ(1, players.getPosition());
}

class TestPlayersImplMultiplePlayers : public TestPlayersImplOnePlayer {
public:
    void SetUp() override
    {
        TestPlayersImplOnePlayer::SetUp();
        players.addPlayer("2");
    }
};

TEST_F(TestPlayersImplMultiplePlayers,
       Given_getName_called_When_multiple_players_added_Then_return_first_player_name)
{
    ASSERT_EQ("1", players.getName());
}
