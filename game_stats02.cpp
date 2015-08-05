#include <iostream>

using namespace std;

int main() {
  unsigned int score = 5000;
  cout << "Score: " << score << endl;

  score += 100;
  cout << "Score: " << score << endl;

  score += 100;
  cout << "Score: " << score << endl;

  int lives = 3;
  ++lives;
  cout << "Lives: " << lives << endl;

  lives = 3;
  lives++;
  cout << "Lives: " << lives << endl;

  lives = 3;
  int bonus = ++lives * 10;
  cout << "lives, bonus = " << lives << ", " << bonus << endl;

  lives = 3;
  bonus = lives++ * 10;
  cout << "lives, bonus = " << lives << ", " << bonus << endl;

  return 0;
}
