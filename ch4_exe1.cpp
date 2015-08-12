#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int c, char** argv) {
  vector<string> games;

  vector<string>::iterator itera;
  vector<string>::const_iterator it;


  int choice;
  string gameName;
  do {
      cout << "\t**Game favorite list**\n\n";
      cout << "please choice a option:\n";
      cout << "1.- Add game\n";
      cout << "2.- Remove game\n";
      cout << "3.- Show list\n";
      cout << "4.- quit\n";
      cin >> choice;


      switch(choice) {
        case 1:
          cout << "Add game\n";
          cout << "write the game name:\n";
          cin >> gameName;
          games.push_back(gameName);
          break;
        case 2:
          cout << "Remove game\n";
          cout << "write the game name:\n";
          cin >> gameName;

          it = find(games.begin(), games.end(), gameName);
          if(it != games.end()) {
            games.erase(it);
            cout << gameName << " game deleted\n" << endl;
          } else {
            cout << "Sorry, this game no exist\n" << endl;
          }
          break;
        case 3:
          cout << "Show list\n";
          for(it = games.begin(); it != games.end(); it++) {
            cout << *it << endl;
          }
          break;
        default:
          break;
      }

  } while(choice != 4);

}
