#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class TicTacToe {
private:
    vector<char> board;
    char player, ai;

public:
    TicTacToe() {
        board = vector<char>(9, ' ');
        player = 'X';
        ai = 'O';
    }

    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            cout << " " << board[i] << " ";
            if ((i + 1) % 3 == 0) {
                cout << "\n";
                if (i < 8) cout << "---+---+---\n";
            } else {
                cout << "|";
            }
        }
        cout << "\n";
    }

    bool isWinner(char symbol) {
        int winCombos[8][3] = {
            {0,1,2}, {3,4,5}, {6,7,8},
            {0,3,6}, {1,4,7}, {2,5,8}, 
            {0,4,8}, {2,4,6}          
        };
        for (auto &combo : winCombos) {
            if (board[combo[0]] == symbol && board[combo[1]] == symbol && board[combo[2]] == symbol)
                return true;
        }
        return false;
    }

    bool isDraw() {
        for (char c : board) {
            if (c == ' ') return false;
        }
        return true;
    }

    void playerMove() {
        int move;
        do {
            cout << "Enter your move (1-9): ";
            cin >> move;
            move--;
        } while (move < 0 || move >= 9 || board[move] != ' ');
        board[move] = player;
    }

    void aiMove() {
        int move;
        do {
            move = rand() % 9;
        } while (board[move] != ' ');
        cout << "AI chooses position " << move + 1 << endl;
        board[move] = ai;
    }

    void playGame() {
        srand(time(0));
        cout << "Welcome to Tic-Tac-Toe!\n";
        displayBoard();

        while (true) {
            playerMove();
            displayBoard();
            if (isWinner(player)) {
                cout << "You win!\n";
                break;
            }
            if (isDraw()) {
                cout << "It's a draw!\n";
                break;
            }

            aiMove();
            displayBoard();
            if (isWinner(ai)) {
                cout << "AI wins!\n";
                break;
            }
            if (isDraw()) {
                cout << "It's a draw!\n";
                break;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}