#include <iostream>
#include <string>

using namespace std;

char ask1();
char ask2(string question);

int main() {
  char answer1 = ask1();
  cout << "Thanks for answering: " << answer1 << endl;

  char answer2 = ask2("Do you wish to save your game?");
  cout << "Thanks for answering: " << answer2 << endl;

  return 0;
}

char ask1() {
  char response;

  do {
    cout << "Please enre 'y' or 'n': ";
    cin >> response;
  } while(response != 'y' && response != 'n');

  return response;
}

char ask2(string question) {
  char response;

  do {
    cout << question << " (y/n): ";
    cin >> response;
  } while(response != 'y' && response != 'n');

  return response;
}
