#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int c, char** argv) {
  srand(static_cast<unsigned int>(time(0)));

  int choice;
  int tries;
  int guess;

  int rangeUp = 100;
  int rangeDown = 1;

  cout << "\t **Welcome Computer Guess**\n\n";
  cout << "please insert a number: ";
  cin >> choice;

  do {
    tries++;

    if(tries) {
      if(guess > choice) {
        rangeUp = choice;
      } else if(guess < choice) {
        rangeDown = choice;
      }
    }

    guess = rand() % rangeUp + rangeDown;

  } while(choice != guess);

  cout << "The computer tries: " << tries << endl;

  return 0;
}
