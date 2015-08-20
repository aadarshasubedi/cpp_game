#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Critter {
public:
  Critter(const string& name = "");
  string getName() const;

private:
  string m_name;
};

Critter::Critter(const string& name):
  m_name(name) {}

inline string Critter::getName() const {
  return m_name;
}

class Farm {
public:
  Farm(int spaces = 1);
  void add(const Critter& aCritter);
  void rollCall() const;

private:
  vector<Critter> m_critter;
};

Farm::Farm(int spaces) {
  m_critter.reserve(spaces);
}

void Farm::add(const Critter& aCritter) {
  m_critter.push_back(aCritter);
}

void Farm::rollCall() const {
  for(vector<Critter>::const_iterator iter = m_critter.begin(); iter != m_critter.end(); iter++) {
    cout << iter->getName() << " here.\n";
  }
}

int main() {
  Critter c("Poochie");
  cout << "My critter's name is " << c.getName() << endl;

  cout << "\nCreating critter farm.\n";
  Farm f(3);

  cout << "\nAdding three critters to the farm.\n";
  f.add(Critter("Moe"));
  f.add(Critter("Larry"));
  f.add(Critter("Curly"));

  cout << "\nCalling Roll...\n";
  f.rollCall();

  return 0;
}
