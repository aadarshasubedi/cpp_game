#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int myRandom(int i) {
  return  rand() % i;
}

int main() {
  srand(unsigned(time(0)));
  vector<int> myvector;

  for(int i = 1; i < 10; i++) {
    myvector.push_back(i);
  }

  random_shuffle(myvector.begin(), myvector.end());

  //random_shuffle(myvector.begin(), myvector.end(), myRandom);

  cout << "myvector contains";
  for(vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
    cout << *it << endl;
  }

  return 0;
}
