#include <iostream>

using namespace std;

class Enemy {
public:
  int m_damage;
  Enemy();
  void attack() const;
};

Enemy::Enemy():
m_damage(10) {

}

void Enemy::attack() const {
  cout << "Attack inflicts " << m_damage << " damage points!\n";
}

class Boss: public Enemy {
public:
  int m_damageMultiplier;
  Boss();
  void specialAttack() const;
};

Boss::Boss():
m_damageMultiplier(3){}

void Boss::specialAttack() const {
  cout << "Special Attack inflicts " << (m_damage * m_damageMultiplier);
  cout << " damage points!\n";
}

int main() {
  cout << "Creating an enemy.\n";
  Enemy enemy1;
  enemy1.attack();

  cout << "Creating a boss.\n";
  Boss boss1;
  boss1.attack();
  boss1.specialAttack();

  return 0;
}
