#include <iostream>

using namespace std;

int main() {
  char again;

  do {
    cout << "\n**Played a exciting game**";
    cout << "\nDo you want play again?(y/n): ";
    cin >> again;
  } while(again == 'y');

  cout << "\nOkey, bye.\n";

  return 0;
}
