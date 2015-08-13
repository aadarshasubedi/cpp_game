#include <iostream>

using namespace std;

void func();

int main(int c, char** argv) {
  int var = 5;
  cout << "In main() var is: " << var << "\n\n";
  func();

  cout << "Back in main() var is: " << var << "\n\n";
  {
    cout << "Creating new var in new scope.\n";
    int var = 10;
    cout << "In main() in the scope var is: " << var << "\n";
  }
}

void func() {
  int var = 5;
  cout << "In func() var is: " << var << "\n\n";

}
