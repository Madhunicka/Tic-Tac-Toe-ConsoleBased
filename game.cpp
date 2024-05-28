#include <iostream>
#include <vector>

using namespace std;


void printBoard(const vector<vector<char>> &board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}


bool checkWin(const vector<vector<char>> &board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; 
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    vector<vector<char>> gameBoard(3, vector<char>(3, ' ')); 

    char currentPlayer = 'X';
    bool gameEnd = false;
    int moves = 0;

    while (!gameEnd && moves < 9) {
        
        printBoard(gameBoard);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || gameBoard[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update board with player move
        gameBoard[row][col] = currentPlayer;

        // Check if player wins
        if (checkWin(gameBoard, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameEnd = true;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        ++moves;
    }

    // If no one wins, it's a draw
    if (!gameEnd) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
