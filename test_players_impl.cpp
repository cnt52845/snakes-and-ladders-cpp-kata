#include <memory>
#include <gtest/gtest.h>
#include "players_impl.h"

class PlayersImplTest : public ::testing::Test {
public:
    void SetUp() override { players = std::make_shared<PlayersImpl>(); }

    std::shared_ptr<PlayersImpl> players;
};

TEST_F(PlayersImplTest, CanAddPlayer)
{
    players->addPlayer("1");
}

TEST_F(PlayersImplTest, CanGetName)
{
    players->addPlayer("1");
    ASSERT_EQ("1", players->getName());
}
