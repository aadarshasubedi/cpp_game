#include <iostream>
#include <string>

using namespace std;

int main() {
  const int MAX_ITEMS = 10;
  string inventary[MAX_ITEMS];

  int numItems = 0;
  inventary[numItems++] = "sword";
  inventary[numItems++] = "armor";
  inventary[numItems++] = "shield";

  cout << "Your items: \n";
  for(int i = 0; i < numItems; i++) {
    cout << inventary[i] << endl;
  }

  cout << "\nYou trade your sword for battle axe.";
  inventary[0] = "battle axe";
  cout << "\nYour items:\n";
  for(int i = 0; i < numItems; i++) {
    cout << inventary[i] << endl;
  }

  cout << "\nThe item name " << inventary[0] << " has ";
  cout << inventary[0].size() << " letters in it.\n";

  cout << "\nYou find a healing potion.";
  if(numItems < MAX_ITEMS) {
    inventary[numItems++] = "healing potion";
  } else {
    cout << "You have too many items and can't carry another";
  }

  cout << "\nYour items: \n";
  for(int i = 0; i < numItems; i++) {
    cout << inventary[i] << endl;
  }

  return 0;
}
