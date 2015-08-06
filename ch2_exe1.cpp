#include <iostream>

using namespace std;

namespace choice {
  enum difficult{
    EASY = 1,
    NORMAL,
    HARD
  };
}

int main(int c, char** argv) {

  int diff;
  cout << "\tDifficulty: \n";
  cout << "1.- Easy\n";
  cout << "2.- Normal\n";
  cout << "3.- Hard\n";

  cout << "\nchoice: ";
  cin >> diff;

  switch(diff) {
    case choice::EASY:
      cout << "You picked Easy.\n";
      break;
    case choice::NORMAL:
      cout << "You picked Normal.\n";
      break;
    case choice::HARD:
      cout << "You picked Hard.\n";
      break;
    default:
      cout << "you made an illega choice.\n";
  }
}
