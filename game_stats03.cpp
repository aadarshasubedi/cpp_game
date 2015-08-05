#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  const int ALIEN_POINT = 150;
  int alliensKilled = 10;
  int score = alliensKilled * ALIEN_POINT;
  cout << "score: " << score << endl;

  enum difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
  difficulty myDifficulty = EASY;

  enum shipCost {FIGHTER_COST=25, BOMBER_COST, CRUISER_COST=50};
  shipCost myShipCost = BOMBER_COST;

  cout << "\nTo Upgrade my ship to a cruiser will cost " << (CRUISER_COST - myShipCost) << " Resource points.\n";

  return 0;
}
