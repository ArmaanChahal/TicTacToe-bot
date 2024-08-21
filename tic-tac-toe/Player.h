#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player {
protected:
    char symbol;

public:
    Player(char symbol);
    virtual void makeMove(Board &board) = 0;
    char getSymbol() const;
};

#endif
