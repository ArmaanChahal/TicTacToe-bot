#include "HumanPlayer.h"
#include <iostream>

// Constructor definition
HumanPlayer::HumanPlayer(char symbol) : Player(symbol) {
    // Any additional initialization (if necessary) can be done here
}

void HumanPlayer::makeMove(Board &board) {
    int row, col;
    std::cout << "Enter row and column (0, 1, or 2) for " << getSymbol() << ": ";
    std::cin >> row >> col;

    // Use the player's symbol when making a move
    while (!board.makeMove(row, col, getSymbol())) {
        std::cout << "Invalid move. Try again: ";
        std::cin >> row >> col;
    }
}
