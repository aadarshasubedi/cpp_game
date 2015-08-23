#include <iostream>

using namespace std;

class Enemy {
public:
  Enemy();
  void attack() const;

protected:
  int damage;
};

Enemy::Enemy():
damage(10) {

}

void Enemy::attack() const {
  cout << "Attack inflicts " << damage << " damage points!\n";
}

class Boss : public Enemy {
public:
  Boss();
  void specialAttack() const;

private:
  int damageMultiplier;
};

Boss::Boss():
damageMultiplier(3) {

}

void Boss::specialAttack() const {
  cout << "Special Attack inflicts " <<(damage * damageMultiplier);
  cout << " damage points!\n";
}

int main() {
  cout << "creating an enemy.\n";
  Enemy enemy1;
  enemy1.attack();

  cout << "\nCreating a boss.\n";
  Boss boss1;
  boss1.attack();
  boss1.specialAttack();

  return 0;
}
