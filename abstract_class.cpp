#include <iostream>

using namespace std;

class Creature {
public:
  Creature(int health= 100);
  virtual void greet() const = 0;
  virtual void displayHealth() const;

protected:
  int health;
};

Creature::Creature(int h):
health(h) {}

void Creature::displayHealth() const {
  cout << "Health: " << health << endl;
}

class Orc : public Creature {
public:
  Orc(int health = 120);
  virtual void greet() const;
};

Orc::Orc(int health):
Creature(health) {}

void Orc::greet() const {
  cout << "The orc grunts hello.\n";
}

int main() {
  Creature* pCreature = new Orc();
  pCreature->greet();
  pCreature->displayHealth();

  return 0;
}
