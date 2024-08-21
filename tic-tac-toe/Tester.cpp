#include "AIPlayer.h"
#include "Board.h"
#include <iostream>

void playAIVsAI(int& aiWins, int& aiDraws, int& aiLosses) {
    Board board;
    AIPlayer aiX('X');  // AI playing as 'X'
    AIPlayer aiO('O');  // AI playing as 'O'

    char winner = '\0';
    bool isDraw = false;

    // AI takes turns to make a move
    while (!board.isDraw() && board.checkWinner() == ' ') {
        aiX.makeMove(board);
        if (board.checkWinner() != ' ') break;
        if (board.isDraw()) break;
        aiO.makeMove(board);
    }

    winner = board.checkWinner();
    isDraw = board.isDraw();

    if (winner == 'X') {
        aiWins++;
        std::cout << "AI 'X' wins!\n";
    } else if (winner == 'O') {
        aiLosses++;
        std::cout << "AI 'O' wins!\n";
    } else if (isDraw) {
        aiDraws++;
        std::cout << "It's a draw!\n";
    }
    std::cout << "-----------------------------------\n";
}

int main() {
    int aiWins = 0;
    int aiDraws = 0;
    int aiLosses = 0;

    const int numberOfGames = 20;

    for (int i = 0; i < numberOfGames; i++) {
        std::cout << "Game " << i + 1 << ":\n";
        playAIVsAI(aiWins, aiDraws, aiLosses);
    }

    std::cout << "\nResults after " << numberOfGames << " games:\n";
    std::cout << "AI 'X' Wins: " << aiWins << "\n";
    std::cout << "Draws: " << aiDraws << "\n";
    std::cout << "AI 'O' Wins: " << aiLosses << "\n";

    return 0;
}