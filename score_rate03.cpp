#include <iostream>

using namespace std;

int main() {
  int score;

  cout << "Enter your score: ";
  cin >> score;

  if(score >= 1000) {
    cout << "You Scored 1000 or more.\n";
  }
  else if(score >= 500) {
    cout << "You Scored 500 or more.\n";
  }
  else if(score >= 250) {
    cout << "You scored 250 or more.\n";
  }
  else {
    cout << "You scored less 250.\n";
  }

  return 0;
}
