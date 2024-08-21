#include "Game.h"
#include <iostream>

// Constructor for the Game class
Game::Game(Player& p1, Player& p2) : player1(&p1), player2(&p2) {
    // Initialize the board and set players
}

// Method to start the game
void Game::play() {
    Player* currentPlayer = player1;
    
    while (!board.isDraw() && board.checkWinner() == ' ') {
        board.displayBoard();
        currentPlayer->makeMove(board);
        
        if (board.checkWinner() != ' ') {
            board.displayBoard();
            std::cout << "Player " << currentPlayer->getSymbol() << " wins!" << std::endl;
            return;
        }

        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
    
    board.displayBoard();
    std::cout << "It's a draw!" << std::endl;
}
