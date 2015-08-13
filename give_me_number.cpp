#include <iostream>

using namespace std;

int askNum(int hight, int low=1);

int main() {
  int number = askNum(5);
  cout << "Thanks for entering: " << number << "\n\n";

  number = askNum(10, 5);
  cout << "Thanks for entering: " << number << "\n\n";

  return 0;
}

int askNum(int high, int low) {
  int num;

  do {
    cout << "Please enter a number" << "(" << low << "-" << high << "):" ;
    cin >> num;
  } while(num > high || num < low);

  return num;
}
