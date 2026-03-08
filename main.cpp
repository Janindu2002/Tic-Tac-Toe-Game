#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << "\n";
    for(int i=0;i<3;i++) {
        cout << " ";
        for(int j=0;j<3;j++) {
            cout << board[i][j];
            if(j<2) cout << " | ";
        }
        cout << "\n";
        if(i<2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin() {

    for(int i=0;i<3;i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return true;
    }

    for(int i=0;i<3;i++) {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return true;
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return true;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return true;

    return false;
}

bool makeMove(int pos, char player) {

    int row = (pos-1)/3;
    int col = (pos-1)%3;

    if(board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = player;
    return true;
}

int main() {

    int position;
    char player = 'X';
    int moves = 0;

    while(true) {

        displayBoard();

        cout << "Player " << player << " enter position (1-9): ";
        cin >> position;

        if(position < 1 || position > 9 || !makeMove(position, player)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        moves++;

        if(checkWin()) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }

        if(moves == 9) {
            displayBoard();
            cout << "Game Draw!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}