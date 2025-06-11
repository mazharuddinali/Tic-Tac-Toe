#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    vector<vector<char>> board;
    char currentPlayer;

    TicTacToe() {
        // Initialize an empty 3x3 board
        board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        currentPlayer = 'X'; // Player X starts the game
    }

    // Function to display the game board
    void displayBoard() {
        cout << "Player X: X  |  Player O: O\n\n";
        cout << "  0   1   2\n";
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << " ---|---|---\n";
        }
        cout << endl;
    }

    // Function to check if there's a winner
    bool checkWinner() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true; // Check row
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true; // Check column
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true; // Check diagonal
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true; // Check anti-diagonal
        return false;
    }

    // Function to check if the board is full
    bool isBoardFull() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false; // Found an empty space
        return true; // Board is full
    }

    // Function to make a move
    void makeMove() {
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Check if the move is valid
        while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again: ";
            cin >> row >> col;
        }
        board[row][col] = currentPlayer; // Place the current player's symbol on the board
    }

    // Function to change the player
    void changePlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Main game loop
    void playGame() {
        while (true) {
            displayBoard();
            makeMove();

            if (checkWinner()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            changePlayer(); // Switch players
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
