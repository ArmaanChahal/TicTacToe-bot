#include "Board.h"

// Initialize the board with empty spaces
Board::Board(int size) : size(size), board(size, std::vector<char>(size, ' ')), currentPlayer('X') {}

// Display the board with numbers for easy reference
void Board::displayBoard() {
    std::cout << "   ";
    for (int i = 0; i < size; ++i) {
        std::cout <<" "<< i << "  ";  // Display column numbers
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << i << " ";  // Display row numbers
        for (int j = 0; j < size; j++) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|\n";
        std::cout << "  ";
        for (int j = 0; j < size; j++) {
            std::cout << "----";
        }
        std::cout << "-\n";
    }
}

// Make a move on the board
bool Board::makeMove(int row, int col, char playerSymbol) {
    if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ') {
        board[row][col] = playerSymbol;
        return true;
    }
    return false;
}

// Reset a move on the board
void Board::resetMove(int row, int col) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        board[row][col] = ' ';
    }
}

// Check if there are any moves left
bool Board::isMovesLeft() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                return true;
            }
        }
    }
    return false;
}

// Check if there's a winner
char Board::checkWinner() {
    // Check rows
    for (int i = 0; i < size; i++) {
        bool rowWin = true;
        for (int j = 1; j < size; j++) {
            if (board[i][j] != board[i][0] || board[i][j] == ' ') {
                rowWin = false;
                break;
            }
        }
        if (rowWin && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < size; i++) {
        bool colWin = true;
        for (int j = 1; j < size; j++) {
            if (board[j][i] != board[0][i] || board[j][i] == ' ') {
                colWin = false;
                break;
            }
        }
        if (colWin && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Check main diagonal
    bool diag1Win = true;
    for (int i = 1; i < size; i++) {
        if (board[i][i] != board[0][0] || board[i][i] == ' ') {
            diag1Win = false;
            break;
        }
    }
    if (diag1Win && board[0][0] != ' ') {
        return board[0][0];
    }

    // Check anti-diagonal
    bool diag2Win = true;
    for (int i = 1; i < size; i++) {
        if (board[i][size - i - 1] != board[0][size - 1] || board[i][size - i - 1] == ' ') {
            diag2Win = false;
            break;
        }
    }
    if (diag2Win && board[0][size - 1] != ' ') {
        return board[0][size - 1];
    }

    return ' ';  // No winner
}


// Check if the game is a draw
bool Board::isDraw() {
    return !isMovesLeft() && checkWinner() == ' ';
}

// Switch the current player
void Board::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Get the current player
char Board::getCurrentPlayer() const {
    return currentPlayer;
}

// Get the symbol at a specific position
char Board::getPosition(int row, int col) const {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return board[row][col];
    }
    return ' ';
}

// Get the size of the board
int Board::getSize() const {
    return size;
}
