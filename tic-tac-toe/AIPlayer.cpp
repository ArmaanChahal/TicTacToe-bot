#include "AIPlayer.h"
#include <limits.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Constructor for AIPlayer
AIPlayer::AIPlayer(char symbol, Difficulty diff) : Player(symbol), difficulty(diff) {
    // Seed random number generator for random move selection
    std::srand(std::time(nullptr));
}

// Function to evaluate the board and return a score
int AIPlayer::evaluate(Board &board, char aiPlayer, char humanPlayer) {
    char winner = board.checkWinner();

    if (winner == aiPlayer) // AI wins
        return 10;
    else if (winner == humanPlayer) // Human wins
        return -10;
    
    return 0; // No winner yet
}

// Minimax function implementation with depth consideration
int AIPlayer::minimax(Board &board, bool isMax, char aiPlayer, char humanPlayer) {
    int score = evaluate(board, aiPlayer, humanPlayer);

    // If someone has won or it's a draw, return the evaluation score
    if (score == 10 || score == -10 || !board.isMovesLeft())
        return score;

    if (isMax) {
        int best = INT_MIN;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getPosition(i, j) == ' ') {
                    board.makeMove(i, j, aiPlayer);
                    best = std::max(best, minimax(board, false, aiPlayer, humanPlayer));
                    board.resetMove(i, j);
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getPosition(i, j) == ' ') {
                    board.makeMove(i, j, humanPlayer);
                    best = std::min(best, minimax(board, true, aiPlayer, humanPlayer));
                    board.resetMove(i, j);
                }
            }
        }
        return best;
    }
}

// Implementation of a random move generator for easy difficulty
int AIPlayer::randomMove(Board &board) {
    int availableMoves[9];
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.getPosition(i, j) == ' ') {
                availableMoves[count] = i * 3 + j;
                count++;
            }
        }
    }

    if (count > 0) {
        int randomIndex = std::rand() % count;
        return availableMoves[randomIndex];
    }
    return -1;
}

// Implementation of the function to find the best move
void AIPlayer::makeMove(Board &board) {
    int bestRow = -1, bestCol = -1;
    char aiPlayer = this->getSymbol();
    char humanPlayer = (aiPlayer == 'X') ? 'O' : 'X';

    if (difficulty == Difficulty::EASY) {
        int move = randomMove(board);
        if (move != -1) {
            bestRow = move / 3;
            bestCol = move % 3;
        }
    } else if (difficulty == Difficulty::MEDIUM) {
        if (std::rand() % 2 == 0) {
            int move = randomMove(board);
            if (move != -1) {
                bestRow = move / 3;
                bestCol = move % 3;
            }
        } else {
            int bestVal = INT_MIN;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board.getPosition(i, j) == ' ') {
                        board.makeMove(i, j, aiPlayer);

                        int moveVal = minimax(board, false, aiPlayer, humanPlayer);

                        board.resetMove(i, j);

                        if (moveVal > bestVal) {
                            bestRow = i;
                            bestCol = j;
                            bestVal = moveVal;
                        }
                    }
                }
            }
        }
    } else {  // HARD difficulty
        int bestVal = INT_MIN;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getPosition(i, j) == ' ') {
                    board.makeMove(i, j, aiPlayer);

                    int moveVal = minimax(board, false, aiPlayer, humanPlayer);

                    board.resetMove(i, j);

                    if (moveVal > bestVal) {
                        bestRow = i;
                        bestCol = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
    }

    board.makeMove(bestRow, bestCol, aiPlayer);
    std::cout << "AI chooses move (" << bestRow << ", " << bestCol << ")" << std::endl;
}
