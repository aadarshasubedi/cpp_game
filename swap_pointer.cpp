#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int* const px, int* const py);

int main() {
  int myScore = 150;
  int yourScore = 1000;

  cout << "Original values\n";
  cout << "myScore: " << myScore << endl;
  cout << "yourScore: " << yourScore << endl;

  cout << "\nCalling badSwap()\n";
  badSwap(myScore, yourScore);
  cout << "myScore: " << myScore << endl;
  cout << "yourScore: " << yourScore << endl;

  cout << "\nCalling goodSwap()\n";
  goodSwap(&myScore, &yourScore);
  cout << "myScore: " << myScore << endl;
  cout << "yourScore: " << yourScore << endl;

  return 0;
}

void badSwap(int x, int y) {
  int temp = x;
   x = y;
   y = temp;
}

void goodSwap(int* const px, int* const py) {
  int temp = *px;
  *px = *py;
  *py = temp;
}
