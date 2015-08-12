#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "Creating scores list.\n";
  vector<int> scores(10, 0);
  cout << "Vector size is: " << scores.size() << endl;
  cout << "vector capacity is: " << scores.capacity() << endl;

  cout << "reserving more memory.\n";
  scores.reserve(20);
  cout << "vector size is: " << scores.size() << endl;
  cout << "vector capacity is: " << scores.capacity() << endl;

}
