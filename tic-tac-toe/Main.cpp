#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "Game.h"
#include <iostream>

int main() {
    int gameMode;
    std::cout << "Choose game mode:\n";
    std::cout << "1. Human vs Human\n";
    std::cout << "2. Human vs AI\n";
    std::cin >> gameMode;

    if (gameMode == 1) {
        HumanPlayer player1('X');
        HumanPlayer player2('O');

        Game game(player1, player2);
        game.play();
    } else if (gameMode == 2) {
        int difficultyChoice;
        std::cout << "Choose AI difficulty:\n";
        std::cout << "1. Easy\n";
        std::cout << "2. Medium\n";
        std::cout << "3. Hard\n";
        std::cin >> difficultyChoice;

        Difficulty difficulty;
        switch (difficultyChoice) {
            case 1:
                difficulty = Difficulty::EASY;
                break;
            case 2:
                difficulty = Difficulty::MEDIUM;
                break;
            case 3:
            default:
                difficulty = Difficulty::HARD;
                break;
        }

        HumanPlayer human('X');
        AIPlayer ai('O', difficulty);

        Game game(human, ai);
        game.play();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}
