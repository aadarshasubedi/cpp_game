#include <iostream>

using namespace std;

class Critter {
public:
  static int s_total;
  static int getTotal();
  Critter(int hunger = 0);

private:
  int m_Hunger;
};

int Critter::s_total = 0;

Critter::Critter(int hunger):
  m_Hunger(hunger) {
  cout << "A critter has been born!" << endl;
  s_total++;
}

int Critter::getTotal() {
  return s_total;
}

int main() {
  cout << "Total number  of critter is: ";
  cout << Critter::s_total << endl;

  Critter c1, c2, c3;

  cout << "\nThe total number of critters is: ";
  cout << Critter::getTotal() << endl;

  return 0;
}
