#include <iostream> // Input/output stream
#include <cstdlib>   // General utilities library
#include <ctime>     // Time functions
#include <windows.h> // Windows-specific functions (used for clearing the console)


using namespace std;

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false; // Empty space found, board is not full
        }
    }
    return true; // Board is full
}
s
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true; // Row win

        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true; // Column win
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true; // Diagonal win

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true; // Diagonal win

    return false; // No win
}

bool makeMove(char board[3][3], int row, int col, char player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        return false; // Invalid move

    board[row][col] = player;
    return true; // Valid move
}

void playTicTacToeAgainstComputer() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);

        int row, col;

        if (currentPlayer == 'X') {
            cout << "Player X, enter your move (row and column): ";
            cin >> row >> col;
        } else {
            // Computer's move
            while(board[row][col] !=' ') {
                row = rand() % 3 + 1;
                col = rand() % 3 + 1;
            }
            cout << "Computer O chooses: " << row + 1 << " " << col + 1 << endl;
        }

        // Adjust user input to match array indices (subtract 1)
        row--;
        col--;

        if (makeMove(board, row, col, currentPlayer)) {
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                if (currentPlayer == 'X') {
                    cout << "Player X wins!" << endl;
                } else {
                    cout << "Computer O wins!" << endl;
                }
                break;
            }

            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!" << endl;
                break;
            }

            if (currentPlayer == 'X'){
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

void playTicTacToeAgainstFriend() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);

        int row, col;

        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Adjust user input to match array indices (subtract 1)
        row--;
        col--;

        if (makeMove(board, row, col, currentPlayer)) {
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!" << endl;
                break;
            }

            if (currentPlayer == 'X'){
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

void playCoinFlipAgainstComputer() {
    srand(time(0));

    cout << "Player 1, choose heads (0) or tails (1): ";
    int player1Choice;
    cin >> player1Choice;

    int result = rand() % 2; // 0 for heads, 1 for tails

    cout << "The coin shows: " << result << endl;

    if (player1Choice == result) {
        cout << "Player 1 wins!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

void playCoinFlipAgainstFriend() {
    srand(time(0));

    cout << "Player 1, choose heads (0) or tails (1): ";
    int player1Choice;
    cin >> player1Choice;

    cout << "Player 2, choose heads (0) or tails (1): ";
    int player2Choice;
    cin >> player2Choice;

    int result = rand() % 2; // 0 for heads, 1 for tails

    cout << "The coin shows: " << result << endl;

    if (player1Choice == result) {
        cout << "Player 1 wins!" << endl;
    } else if (player2Choice == result) {
        cout << "Player 2 wins!" << endl;
    } else {
        cout << "Both loose!" << endl;
    }
}

void playRockPaperScissorsAgainstFriendHidden() {
    int player1Choice, player2Choice;

    cout << "Player 1, enter your choice (Rock: 0, Paper: 1, Scissors: 2): ";
    cin >> player1Choice;

    // Clear screen to hide player 1's choice
    system("cls");

    cout << "Player 2, enter your choice (Rock: 0, Paper: 1, Scissors: 2): ";
    cin >> player2Choice;

    // Clear screen to hide player 2's choice
    system("cls");

    // Logic to determine the winner
    if (player1Choice == player2Choice) {
        cout << "It's a tie!" << endl;
    } else if ((player1Choice == 0 && player2Choice == 2) || // &-and ,|| or
               (player1Choice == 1 && player2Choice == 0) ||
               (player1Choice == 2 && player2Choice == 1)) {
        cout << "Player 1 wins!" << endl;
    } else {
        cout << "Player 2 wins!" << endl;
    }

    // Display the choices if needed
    cout << "Player 1 chose: " << player1Choice << endl;
    cout << "Player 2 chose: " << player2Choice << endl;
}


void playRockPaperScissorsAgainstComputer() {
    srand(time(0));

    cout << "Player 1, choose Rock (0), Paper (1), or Scissors (2): ";
    int playerChoice;
    cin >> playerChoice;

    int computerChoice = rand() % 3; // 0 for Rock, 1 for Paper, 2 for Scissors

    cout << "You chose: " << playerChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;

    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "Game Hub Menu:" << endl;
        cout << "1. Tic Tac Toe" << endl;
        cout << "2. Coin Flip" << endl;
        cout << "3. Rock, Paper, Scissors" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Do you want to play against a friend (1) or computer (2)? ";
                int tttChoice;
                cin >> tttChoice;
                if (tttChoice == 1) {
                    playTicTacToeAgainstFriend();
                } else if (tttChoice == 2) {
                    playTicTacToeAgainstComputer();
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                break;
            case 2:
                cout << "Do you want to play against a friend (1) or computer (2)? ";
                int cfChoice;
                cin >> cfChoice;
                if (cfChoice == 1) {
                    playCoinFlipAgainstFriend();
                } else if (cfChoice == 2) {
                    playCoinFlipAgainstComputer();
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                break;
            case 3:
                cout << "Do you want to play against a friend (1) or computer (2)? ";
                int pchoice;
                cin >> pchoice;
                if(pchoice == 1){
                    playRockPaperScissorsAgainstFriendHidden();
                } else if(pchoice == 2){
                playRockPaperScissorsAgainstComputer();
                }
                break;
            case 4:
                cout << "Exiting Game Hub. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}




