#include <iostream>
#include <string>

using namespace std;

int main(int c, char** argv) {
  const int ROWS = 3;
  const int COLUMNS = 3;

  char board[ROWS][COLUMNS] = {
    {'0', 'X', '0'}, {' ', 'X', 'X'}, {'X', '0', '0'}
  };

  cout << "Here's the Tic-Tac-Toe board:\n";
  for(int i = 0; i < ROWS; i ++) {
    for(int j = 0; j < COLUMNS; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }

  cout << "\n'X' move to the empty location.\n\n";
  board[1][0] = 'X';

  cout << "Now the Tic-Tac-Toe board is:\n";
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLUMNS; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }

  cout << "\n'X' wins!\n";
  return 0;
}
