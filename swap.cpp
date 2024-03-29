#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int& x, int& y);

int main() {
  int myScore = 150;
  int yourScore = 1000;

  cout << "Original values\n";
  cout << "myScore: " << myScore << endl;
  cout << "yourScore: " << yourScore << endl;

  cout << "Calling badSwap()\n";
  badSwap(myScore, yourScore);
  cout << "myScore: " << myScore << endl;
  cout << "yourScore: " << yourScore << endl;

  cout << "Calling goodSwap()\n";
  goodSwap(myScore, yourScore);
  cout << "myScore: " << myScore << endl;
  cout << "yourScore: " << yourScore << endl;

  return 0;
}

void badSwap(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}

void goodSwap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}
