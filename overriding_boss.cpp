#include <iostream>

using namespace std;

class Enemy {
public:
  Enemy(int damage = 10);
  void virtual taunt() const;
  void virtual attack() const;

private:
  int damage;
};

Enemy::Enemy(int d):
damage(d) {

}

void Enemy::taunt() const {
  cout << "The enemy says he will fight you.\n";
}

void Enemy::attack() const {
  cout << "Attack! Inflicts " << damage << " damage points.";
}

class Boss: public Enemy {
public:
  Boss(int damage = 30);
  void virtual taunt() const;
  void virtual attack() const;
};

Boss::Boss(int damage):
Enemy(damage) {

}

void Boss::taunt() const{
  cout << "The boss says he will end your pitful existence.\n";
}

void Boss::attack() const {
  Enemy::attack();
  cout << " And laughs heartily at you.\n";
}

int main() {
  cout << "Enemy  object:\n";
  Enemy enemy;
  enemy.taunt();
  enemy.attack();

  cout << "\n\nBoss object:\n";
  Boss boss;
  boss.taunt();
  boss.attack();

  return 0;
}
