#include <iostream>

using namespace std;

int main() {
  int myScore = 1000;
  int& mikeScore = myScore;

  cout << "myScore is: " << myScore << endl;
  cout << "mikeeScore is: " << mikeScore << "\n\n";

  cout << "Adding 500 to myScore" << endl;
  myScore += 500;
  cout << "myScore is: " << myScore << endl;
  cout << "mikeScore is: " << mikeScore << "\n\n";

  cout << "Adding to mikeScore" << endl;
  mikeScore += 500;
  cout << "myScore is:  " << myScore << endl;
  cout << "mikeScore is: " << mikeScore << "\n\n";

  return 0;
}
