#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

class Board {
private:
    int size;  // Size of the board (3x3, 5x5, etc.)
    std::vector<std::vector<char>> board;  // Dynamic 2D vector for the board
    char currentPlayer;  // This tracks the current player ('X' or 'O')

public:
    Board(int size = 3);  // Constructor to initialize the board with a given size

    void displayBoard();  // Display the board with numbers for user reference
    
    bool makeMove(int row, int col, char playerSymbol);  // Make a move on the board
    
    char checkWinner();  // Check if there's a winner
    
    bool isDraw();  // Check if the game is a draw
    
    void switchPlayer();  // Switch the current player
    
    void resetMove(int row, int col);  // Reset a move on the board
    
    bool isMovesLeft();  // Check if there are any moves left
    
    char getCurrentPlayer() const;  // Get the current player
    
    char getPosition(int row, int col) const;  // Get the symbol at a specific position

    int getSize() const;  // Get the size of the board
};

#endif
