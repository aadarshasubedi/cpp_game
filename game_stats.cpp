
#include <iostream>

using namespace std;

int main() {
  int score = 0;
  double distance = 1200.76;
  char playAgain = 'y';
  bool shieldsUp = true;

  short lives = 3, aliensKilled = 10;
  double engineTemp = 6572.89;

  int fuel;

  cout << "\nScore: " << score << endl;
  cout << "Distance: " << distance << endl;
  cout << "PlayAgain: " << playAgain << endl;

  cout << "Lives: " << lives << endl;
  cout << "EngineTemp" << engineTemp << endl;

  cout << "\nHow much Fuel? ";
  cin >> fuel;
  cout << "Fuel: " << fuel << endl;

  typedef unsigned short int ushort;
  ushort bonus = 10;
  cout << "\nBonus: " << bonus << endl;

  return 0;
}
