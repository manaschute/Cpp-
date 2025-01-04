#include <iostream>
#include <limits>

using namespace std;


char turn = 'X';
int draw = 0;
char winner = ' ';
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

class tictactoe {
public:

    void display_board() {
        cout<<endl;
        cout << "Game Board" << endl<<endl<<endl;

        cout <<"            "<<board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout <<"            "<< "-" << " | " << "-" << " | " << "-"<< endl;

        cout <<"            "<< board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout <<"            "<< "-" << " | " << "-" << " | " << "-" <<endl;

        cout <<"            "<< board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout <<"            "<< "-" << " | " << "-" << " | " << "-" <<endl;
    }

    void playerturn() {
        int row = -1;
        int column = -1;
        int input = -1;
        cout << "TURN " << turn << endl;

        while (true) {
            cout << "Player " << turn << " please give your input" << endl;
            cin >> input;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignores invalid input
                cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            } else if (input >= 1 && input <= 9) {
                if (input == 1) {
                    row = 0;
                    column = 0;
                } else if (input == 2) {
                    row = 0;
                    column = 1;
                } else if (input == 3) {
                    row = 0;
                    column = 2;
                } else if (input == 4) {
                    row = 1;
                    column = 0;
                } else if (input == 5) {
                    row = 1;
                    column = 1;
                } else if (input == 6) {
                    row = 1;
                    column = 2;
                } else if (input == 7) {
                    row = 2;
                    column = 0;
                } else if (input == 8) {
                    row = 2;
                    column = 1;
                } else if (input == 9) {
                    row = 2;
                    column = 2;
                }

                if (board[row][column] != 'X' && board[row][column] != 'O') {
                    board[row][column] = turn;
                    break;
                } else {
                    cout << "Place is already filled, please enter at some other place" << endl;
                }
            } else {
                cout << "Enter a valid number" << endl;
            }
        }
    }

    bool check_result() {
        for (int i = 0; i < 3; ++i) { // Check each row
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = board[i][0];
                return false;
            }
        }

        for (int i = 0; i < 3; ++i) { // Check each column
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                winner = board[0][i];
                return false;
            }
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
            return false;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
            return false;
        }

        for (int i = 0; i < 3; ++i) { // Check if any cells are empty
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 'X' && board[i][j] != 'O') { // If this is true, then there are some empty cells
                    return true; // Game is still on
                }
            }
        }

        draw = 1;
        return false; // Game draw, no places left
    }
};

int main() {
    tictactoe obj;

    cout<<"Player 1- 'X' and Player 2- 'O' Welcome to the game"<<endl<<endl;
    cout<<"player 'X' will play first"<<endl;

    while (obj.check_result()) {
        obj.display_board();
        obj.playerturn();

        if (turn == 'X') {
            turn = 'O';
        } else {
            turn = 'X';
        }
    }

    cout << endl << endl << endl << endl << endl;
    cout << "Display Final Board" << endl;
    obj.display_board();

    if (draw) {
        cout << "Draw" << endl;
    } else {
        cout << "Congrats! Winner is " << winner << endl;
    }

    return 0;
}
