#include <iostream>
#include <string>

using namespace std;

int main() {
  string username;
  string password;
  bool success;

  cout << "\nGame designer's network\n";

  do {
    cout << "\nUsername: ";
    cin >> username;

    cout << "\nPassword: ";
    cin >> password;

    if(username == "S.meier" && password == "civilization") {
      cout << "\nHey Sid.\n";
      success = true;
    } else if (username == "S.Miyamoto" && password == "mariobros") {
      cout << "\nWhat's up. Miyamoto\n";
      success = true;
    } else if (username == "S.Wright" && password == "sims") {
      cout << "\nHow's it going, Will?\n";
      success = true;
    } else if(username == "guest" || password == "guest") {
      cout << "Welcome, guest\n";
      success = true;
    } else {
      cout << "Your login failed.\n";
      success = false;
    }

  } while(!success);

  return 0;
}
