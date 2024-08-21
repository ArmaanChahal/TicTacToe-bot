#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(char symbol);  // Constructor declaration
    virtual void makeMove(Board &board) override;
};

#endif
