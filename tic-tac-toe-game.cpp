#include <iostream>
using namespace std;

// The board (3x3 grid)
char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

// Function to draw the board
void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

// Function to check if someone won
char checkWinner() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' '; // no winner yet
}


int main() {
    char player = 'X';  // first player is X
    int move;
    int movesCount = 0;

    while (true) {
        drawBoard(); // show board
        cout << "Player " << player << ", choose a cell (1-9): ";
        cin >> move;

        // calculate row and column
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // check if the cell is free
        if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // mark the move
        board[row][col] = player;
        movesCount++;

        // check winner
        char winner = checkWinner();
        if (winner == 'X' || winner == 'O') {
            drawBoard();
            cout << "Player " << winner << " wins \n";
            break;
        }

        // check draw
        if (movesCount == 9) {
            drawBoard();
            cout << "It's a draw \n";
            break;
        }

        // switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
