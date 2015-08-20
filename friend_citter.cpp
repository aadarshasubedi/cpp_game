#include <iostream>
#include <vector>

using namespace std;

class Critter {
  friend void peek(const Critter& aCritter);
  friend ostream& operator<<(ostream& os, const Critter& aCritter);
public:
  Critter(const string  & name = "");

private:
  string m_name;
};

Critter::Critter(const string& name):
  m_name(name) {}

void peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);

int main() {
  Critter c("Poochie");

  cout << "Calling Peek() to access c's private data member, m_name: \n";
  peek(c);

  cout << "\nSending c object to cout with the << operator ";
  cout << c << endl;

  return 0;
}

void peek(const Critter& aCritter) {
  cout << aCritter.m_name << endl;
}

ostream& operator<<(ostream& os, const Critter& aCritter) {
  os << "Critter Object - ";
  os << "m_name: " << aCritter.m_name;

  return os;
}
