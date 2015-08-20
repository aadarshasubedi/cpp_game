#include <iostream>

using namespace std;

class Critter {
public:
  Critter(int hunger = 0);
  int GetHunger() const;
  void SetHunger(int hunger);

private:
  int m_Hunger;
};

Critter::Critter(int hunger):
  m_Hunger(hunger)
{
  cout << "A new critter has been born" << endl;
}

int Critter::GetHunger() const {
  return m_Hunger;
}

void Critter::SetHunger(int hunger) {
  if(hunger < 0) {
    cout << "You can't set a critter's hunger to a negative number.\n\n";
  } else {
    m_Hunger = hunger;
  }
}

int main() {
  Critter cri(5);
  //cout << c.m_Hunger << endl //Illegal!!
  cout << "Calling GetHunger(): " << cri.GetHunger() << endl;
  cout << "Calling SetHunger(-1): " << endl;
  cri.SetHunger(-1);
  cout << "Calling SetHunger(9): " << endl;
  cri.SetHunger(9);
  cout << "Calling GetHunger(): " << cri.GetHunger() << endl;

  return 0;
}
