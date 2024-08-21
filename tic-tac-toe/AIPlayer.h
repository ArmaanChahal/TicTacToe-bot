#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "Board.h"

enum class Difficulty {
    EASY,
    MEDIUM,
    HARD
};

class AIPlayer : public Player {
public:
    AIPlayer(char symbol, Difficulty difficulty);

    void makeMove(Board &board) override;

private:
    Difficulty difficulty;
    int evaluate(Board &board, char aiPlayer, char humanPlayer);
    int minimax(Board &board, bool isMax, char aiPlayer, char humanPlayer);
    int randomMove(Board &board);
};

#endif
