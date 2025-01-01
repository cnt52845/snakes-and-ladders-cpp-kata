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

TEST_F(TestPlayersImplMultiplePlayers,
       Given_getName_called_When_nextPlayer_called_Then_return_second_player_name)
{
    players.nextPlayer();
    ASSERT_EQ("2", players.getName());
}

TEST_F(TestPlayersImplMultiplePlayers,
       Given_getName_called_When_nextPlayer_called_twice_Then_wrap_and_return_first_player_name)
{
    players.nextPlayer();
    players.nextPlayer();
    ASSERT_EQ("1", players.getName());
}

TEST(TestPlayersImpl, Integration)
{
    std::shared_ptr<PlayersImpl> players{std::make_shared<PlayersImpl>()};

    players->nextPlayer();
    ASSERT_EQ("", players->getName());
    ASSERT_EQ(0, players->getPosition());

    players->addPlayer("1");
    players->addPlayer("2");

    ASSERT_EQ("1", players->getName());
    ASSERT_EQ(0, players->getPosition());
    players->setPosition(1);
    ASSERT_EQ(1, players->getPosition());

    players->nextPlayer();
    ASSERT_EQ("2", players->getName());
    ASSERT_EQ(0, players->getPosition());
    players->setPosition(2);
    ASSERT_EQ(2, players->getPosition());

    players->nextPlayer();
    ASSERT_EQ("1", players->getName());
    ASSERT_EQ(1, players->getPosition());

    players->nextPlayer();
    ASSERT_EQ("2", players->getName());
    ASSERT_EQ(2, players->getPosition());
}
