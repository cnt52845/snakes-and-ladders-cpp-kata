#pragma once

class Players {
public:
    virtual std::string getName() const           = 0;
    virtual int         getPosition() const       = 0;
    virtual void        setPosition(int position) = 0;
    virtual void        nextPlayer()              = 0;
};
