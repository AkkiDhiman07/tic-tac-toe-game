#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
bool tie;
char token = 'X';
string n1, n2;

void functionone() {
    cout << "   |   |   \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
    cout << "   |   |   \n";
}

void functiontwo() {
    int digit;
    if (token == 'X') {
        cout << n1 << " please enter a number: ";
        cin >> digit;
    } else {
        cout << n2 << " please enter a number: ";
        cin >> digit;
    }

    if (digit < 1 || digit > 9) {
        cout << "Invalid input!" << endl;
        functiontwo();  // Ask for input again.
        return;
    }

    // Calculate the row and column from the input digit.
    row = (digit - 1) / 3;
    column = (digit - 1) % 3;

    if (space[row][column] != 'X' && space[row][column] != 'O') {
        space[row][column] = token;
        token = (token == 'X') ? 'O' : 'X';
    } else {
        cout << "That space is already taken!" << endl;
        functiontwo();  // Ask for input again.
    }
}

bool functionthree() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }

    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player:\n";
    cin.ignore();
    getline(cin, n1);
    cout << "Enter the name of the second player:\n";
    getline(cin, n2);
    cout << n1 << " is the first player, so they will play first!!!\n";
    cout << n2 << " is the second player, so they will play after the first!!!\n";

    while (!functionthree()) {
        functionone();
        functiontwo();
    }

    functionone();  // Display the final board.

    if (tie) {
        cout << "It's a tie!" << endl;
    } else if (token == 'X') {
        cout << n2 << " wins!!" << endl;
    } else {
        cout << n1 << " wins!!" << endl;
    }

    return 0;
}

