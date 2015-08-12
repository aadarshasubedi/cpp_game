#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "Creating a 10 element vector to hold scores.\n";
  vector<int> scores(10, 0);
  cout << "Vector size is: " << scores.size() << endl;
  cout << "Vector capacity is: " << scores.capacity() << endl;
  cout << "adding a score.\n";
  scores.push_back(0);
  cout << "vector size is: " << scores.size() << endl;
  cout << "vector capacity is: " << scores.capacity() << endl;
  cout << "adding other score.\n";
  scores.push_back(0);
  cout << "vector size is: " << scores.size() << endl;
  cout << "vector capacity is: " << scores.capacity() << endl;
  cout << "deleting one score.\n";
  scores.pop_back();
  cout << "vector size is: " << scores.size() << endl;
  cout << "vector capacity is: " << scores.capacity() << endl;;
}
