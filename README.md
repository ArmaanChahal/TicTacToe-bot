
# TicTacToe-bot

This is a console-based Tic-Tac-Toe game implemented in C++. The game supports Human vs. Human and Human vs. AI modes with different difficulty levels for the AI.

## Features

- **Human vs Human**: Two players can play against each other by taking turns.
- **Human vs AI**: A single player can play against the AI with three difficulty levels:
  - **Easy**: AI makes random moves.
  - **Medium**: AI makes a mix of random and optimal moves.
  - **Hard**: AI plays optimally using the Minimax algorithm.

## How to Play

### Setup

1. Clone the repository to your local machine:

   ```sh
   git clone https://github.com/ArmaanChahal/TicTacToe-bot.git
   cd TicTacToe-bot
   ```

2. Compile the code using a C++ compiler:

   ```sh
   g++ -std=c++11 Main.cpp Board.cpp Player.cpp HumanPlayer.cpp AIPlayer.cpp Game.cpp -o tictactoe
   ```

3. Run the executable:

   ```sh
   ./tictactoe
   ```

### Game Modes

After running the game, you'll be prompted to choose a game mode:

1. **Human vs Human**: Both players take turns playing on the same console.
2. **Human vs AI**: Play against the AI with a choice of difficulty levels.

### Controls

- The game board is represented by a grid with numbers indicating positions 0-2 for rows and 0-2 for columns.
- Enter the number corresponding to the position where you want to place your move in this format ( number number)

### Example:

```
Choose game mode:
1. Human vs Human
2. Human vs AI
> 2

Choose AI difficulty:
1. Easy
2. Medium
3. Hard
> 3


```
![image](https://github.com/user-attachments/assets/d6160cad-7206-4851-b9d1-4b7cb3d3479c)

## Project Structure

- `Main.cpp`: Entry point of the game, where the game mode is selected and the game is started.
- `Board.h` / `Board.cpp`: Handles the Tic-Tac-Toe board, including displaying the board, making moves, and checking for winners.
- `Player.h`: Abstract base class for players (human or AI).
- `HumanPlayer.h` / `HumanPlayer.cpp`: Handles the logic for human players.
- `AIPlayer.h` / `AIPlayer.cpp`: Implements the AI player using the Minimax algorithm with different difficulty levels.
- `Game.h` / `Game.cpp`: Manages the overall game flow, switching turns between players and checking game status.

## Customization

- **Grid Size**: The game currently supports a 3x3 grid. You can modify the grid size by updating the `Board` class.
- **AI Difficulty**: The AI uses the Minimax algorithm for decision-making. You can adjust the AI's behavior in the `AIPlayer.cpp` file.

## Future Enhancements

- Add a graphical user interface (GUI) for a more interactive experience.
- Implement a networked version for playing over the internet.
- Expand AI difficulty levels with more sophisticated algorithms.

## Contributing

Contributions are welcome! Please fork this repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

You can use this README as the `README.md` file in your GitHub repository. It provides a clear overview of your project, instructions for setting it up, and how to use it.
