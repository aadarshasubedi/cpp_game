#include <iostream>

using namespace std;

class Critter {
  public:
    int m_Hunger;
    Critter(int hunger = 0);
    void Greet();
};

Critter::Critter(int hunger) {
  cout << "A new Critter has born!" << endl;
  m_Hunger = hunger;
}

void Critter::Greet() {
  cout << "Hi, I'm a critter. My hunger level is " << m_Hunger << "\n\n";
}

int main() {
  Critter c(7);
  c.Greet();

  return 0;
}
