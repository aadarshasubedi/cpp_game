#include <iostream>

using namespace std;

int main() {
  int score1, score2, score3;

  cout << "\nScore #1: ";
  cin >> score1;

  cout << "\nScore #2: ";
  cin >> score2;

  cout << "\nScore #3: ";
  cin >> score3;

  cout << "The average score is " << (score1 + score2 + score3) / 3 << "points" << endl;

  return 0;
}
