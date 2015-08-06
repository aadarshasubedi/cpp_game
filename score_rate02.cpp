#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int score;

  cout << "Enter your score: ";
  cin >> score;

  if(score >= 1000) {
    cout << "You scored 1000 or more. Impressive\n";
  }
  else
  {
    cout << "You scored less than 1000. \n";
  }

  return 0;  
}
