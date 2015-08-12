#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int randomDesorder(int i) {
  return rand() % i;
}

int main(int c, char** argv) {
  vector<int>::const_iterator iter;

  cout << "Creating a list of scores.";
  vector<int> scores;
  scores.push_back(1500);
  scores.push_back(3500);
  scores.push_back(7500);

  cout << "\nHigh Scores:\n";
  for(iter = scores.begin(); iter != scores.end(); iter++) {
    cout << *iter << endl;
  }

  cout << "\nFinding a score.";
  int score;
  cout << "\nEnter a score to find: ";
  cin >> score;

  iter = find(scores.begin(), scores.end(), score);

  if(iter != scores.end()) {
    cout << "Score found.\n";
  } else {
    cout << "Score not found.\n";
  }

  cout << "\nRandomizing scores.";
  srand(unsigned(time(0)));
  random_shuffle(scores.begin(), scores.end(), randomDesorder);
  cout << "\nHigh Scores:\n";
  for (iter = scores.begin(); iter != scores.end(); ++iter) {
    cout << *iter << endl;
  }

  cout << "\nSorting scores.";
  sort(scores.begin(), scores.end());
  cout << "\nHigh Scores:\n";
  for(iter = scores.begin(); iter != scores.end(); iter++) {
    cout << *iter << endl;
  }

  return 0;
}
