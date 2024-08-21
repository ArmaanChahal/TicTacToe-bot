#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
private:
    Board board;
    Player* player1;
    Player* player2;

public:
    Game(Player& p1, Player& p2);
    void play();
};

#endif
