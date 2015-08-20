#include <iostream>

using namespace std;

class Critter {
public:
  Critter(int hunger = 0, int boredom = 0);
  void talk();
  void eat(int food = 4);
  void play(int fun = 4);

private:
  int m_hunger;
  int m_bored;

  int getMood() const;
  void passTime(int time = 1);
};

Critter::Critter(int hunger, int boredom):
  m_hunger(hunger), m_bored(boredom) {}

inline int Critter::getMood() const {
  return (m_hunger + m_bored);
}

void Critter::passTime(int time) {
  m_hunger += time;
  m_bored += time;
}

void Critter::talk() {
  cout << "I'm a critter, i feel ";

  int mood = getMood();

  if(mood > 15) {
    cout << "Mad.\n";
  } else if(mood > 10) {
    cout << "Frustrated.\n";
  } else if(mood > 5) {
    cout << "Ok.\n";
  } else {
    cout << "Happy.\n";
  }

  passTime();
}

void Critter::eat(int food) {
  cout << "Brrupp.\n";
  m_hunger -= food;

  if(m_hunger < 0) {
    m_hunger = 0;
  }

  passTime();
}

void Critter::play(int fun) {
  cout << "Wheee!.\n";
  m_bored -= fun;

  if(m_bored < 0) {
    m_bored = 0;
  }

  passTime();
}

int main() {
  Critter c;
  c.talk();

  int choice;
  do {
    cout << "\t**Critter Caretaker**\n\n";
    cout << "0 - Quit.\n";
    cout << "1 - Listen to you critter.\n";
    cout << "2 - Feed your critter.\n";
    cout << "3 - Play with your critter.\n";

    cout << "Choice: ";
    cin >> choice;

    switch(choice) {
      case 0:
        cout << "Good-bye!.\n";
        break;
      case 1:
        c.talk();
        break;
      case 2:
        c.eat();
        break;
      case 3:
        c.play();
        break;
      default:
        cout << "\nSorry, but " << choice << " isn't valid choice.\n";
    }

  } while(choice != 0);

  return 0;
}
