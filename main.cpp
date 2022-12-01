#include <iostream>
#include <string>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

const string X_LETTER = "X";
const string O_LETTER = "O";
const string EMPTY_CELL = " ";

void runGame();
void initializeBoard(string gameBoard[ROWS][COLS]);
void printBoard(string gameBoard[ROWS][COLS]);
void writeLetter(string position, string letterTurn, string gameBoard[ROWS][COLS]);
string getUserPosition(string letterTurn, string gameBoard[ROWS][COLS]);
bool isPositionOccupied(string position, string gameBoard[ROWS][COLS]);
bool isWinner(string letterTurn, string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);

int main() {

    runGame();

    return 0;
}

void runGame() {

    string gameBoard[ROWS][COLS] {};
    string letterTurn = "X";

    initializeBoard(gameBoard);
    printBoard(gameBoard);

    /*
    LOOP until user wins or game is tied:
        1. get user input (positions 0-2 for rows and columns) (user is X by default)
        2. validate user input is correct + position is not occupied
        3. write user's position to gameBoard array
        4. check if user won or gameBoard is full (tie)
    */

   while (true) {

    string userPosition;
    bool occupied = false;
    
    userPosition = getUserPosition(letterTurn, gameBoard);
    occupied = isPositionOccupied(userPosition, gameBoard);
    if (occupied) {
        cout << "Position occupied, choose another please.. " << endl;
        continue;
    }
    writeLetter(userPosition, letterTurn, gameBoard);
    printBoard(gameBoard);

    if (isWinner(letterTurn, gameBoard)) {
        cout << "Congrats, player " << letterTurn << " Won!" << endl;
        break;
    }

    if (isBoardFull(gameBoard)) {
        cout << "it is a cat's game!, a TIE. " << endl;
        break;
    }

    letterTurn = letterTurn == X_LETTER ? O_LETTER : X_LETTER;

   }
   
}

void initializeBoard(string gameBoard[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = EMPTY_CELL;
        }
    }
}

void printBoard(string gameBoard[ROWS][COLS]){

    cout << "---\t---\t---" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << " " << gameBoard[i][j] << "\t";
        }
        cout << endl;
        cout << "---\t---\t---" << endl;
    }
}

// TODO: improve input range from 0-2 to 1-3
// TOOD: add extra validation of user input before extracting begin & back [such as enter key]
string getUserPosition(string letterTurn, string gameBoard[ROWS][COLS]) {

    string position;

    cout << "this is letter's " << letterTurn << " turn, please enter your desired row THEN column seperated by comma." << endl;
    getline(cin, position);

    cout << *position.begin() << endl;
    cout << position.back() << endl;

    int row = *position.begin() - '0';
    int col = position.back() - '0';

    while (!((row >= 0 && row <= 2) && (col >= 0 && col <= 2))) {

        cout << "this is letter's " << letterTurn << " turn, please enter your desired row THEN column seperated by comma. [ROW,COLUMN] ex. 0,2" << endl;
        getline(cin, position);

        row = *position.begin() - '0';
        col = position.back() - '0';
    }

    return position;

}

bool isPositionOccupied(string position, string gameBoard[ROWS][COLS]) {

    int row = *position.begin() - '0';
    int col = position.back() - '0';

    return !(gameBoard[row][col] == EMPTY_CELL);
}

void writeLetter(string position, string letterTurn, string gameBoard[ROWS][COLS]) {

    int row = *position.begin() - '0';
    int col = position.back() - '0';

    gameBoard[row][col] = letterTurn;
}

bool isWinner(string letterTurn, string gameBoard[ROWS][COLS]) {

    bool winner = false;

    // Rows
    if ((gameBoard[0][0] == letterTurn) && (gameBoard[0][1] == letterTurn) && (gameBoard[0][2] == letterTurn))
    {
        winner = true;
    }
    else if ((gameBoard[1][0] == letterTurn) && (gameBoard[1][1] == letterTurn) && (gameBoard[1][2] == letterTurn))
    {
        winner = true;
    }
    else if ((gameBoard[2][0] == letterTurn) && (gameBoard[2][1] == letterTurn) && (gameBoard[2][2] == letterTurn))
    {
        winner = true;
    }

    // Cols
    else if ((gameBoard[0][0] == letterTurn) && (gameBoard[1][0] == letterTurn) && (gameBoard[2][0] == letterTurn))
    {
        winner = true;
    }
    else if ((gameBoard[0][1] == letterTurn) && (gameBoard[1][1] == letterTurn) && (gameBoard[2][1] == letterTurn))
    {
        winner = true;
    }
    else if ((gameBoard[0][2] == letterTurn) && (gameBoard[1][2] == letterTurn) && (gameBoard[2][2] == letterTurn))
    {
        winner = true;
    }

    // Diagonals
    else if ((gameBoard[0][0] == letterTurn) && (gameBoard[1][1] == letterTurn) && (gameBoard[2][2] == letterTurn))
    {
        winner = true;
    }
    else if ((gameBoard[0][2] == letterTurn) && (gameBoard[1][1] == letterTurn) && (gameBoard[2][0] == letterTurn))
    {
        winner = true;
    }

    return winner;
}

bool isBoardFull(string gameBoard[ROWS][COLS]) {
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (gameBoard[i][j] == EMPTY_CELL) {
                return false;
            }
        }
    }

    return true;
    
}
    