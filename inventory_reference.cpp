#include <iostream>
#include <string>
#include <vector>

using namespace std;

string& refToElement(vector<string>& inventory, int i);

int main(int c, char** argv) {
  vector<string> inventory;
  inventory.push_back("sword");
  inventory.push_back("armor");
  inventory.push_back("shield");

  cout << "Sending the returned reference to cout:\n";
  cout << refToElement(inventory, 0) << endl;

  cout << "Assigning the returned reference to another reference. \n";
  string& rStr = refToElement(inventory, 1);
  cout << "Sending the new reference to cout:\n";
  cout << rStr << "\n\n";

  cout << "Assigning the returned reference to a string reference.\n";
  string str = refToElement(inventory, 1);
  cout << "Sendind the new object to cout:\n";
  cout << str << "\n\n";

  cout << "Altering an object through a returned reference.\n";
  rStr = "Healding Potion";
  cout << "Sending the altered object cout:\n";
  cout << inventory[1] << endl;

  return 0;
}

string& refToElement(vector<string>& inventory, int i) {
  return inventory[i];
}
