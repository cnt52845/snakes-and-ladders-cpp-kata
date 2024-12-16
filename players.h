#pragma once

class Players {
public:
    virtual void        addPlayer(std::string name) = 0;
    virtual std::string getName() const             = 0;
};
