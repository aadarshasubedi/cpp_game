#include <iostream>

using namespace std;

class Critter {
  public:
    int m_Hunger;
    void Greet();
};

void Critter::Greet() {
  cout << "Hi. I'm a critter, My hunger level is " << m_Hunger << ".\n";
}

int main(int c, char** argv) {
  Critter c1, c2;

  c1.m_Hunger = 9;
  cout << "critter1's hunger level is " << c1.m_Hunger << endl;

  c2.m_Hunger = 3;
  cout << "critter2's hunger level is " << c2.m_Hunger << endl;

  c1.Greet();
  c2.Greet();

  return 0;
}
