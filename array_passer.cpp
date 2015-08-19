#include <iostream>

using namespace std;

void increase(int* const array, const int NUM_ELEMENTS);
void display(const int* const array, const int NUM_ELEMENTS);

int main() {
  cout << "Creating an array of high score.\n";
  const int NUM_SCORES = 3;
  int highScores[NUM_SCORES] = {500, 3500, 2700};

  cout << "Displaying score using array name as a constant pointer.\n";
  cout << *highScores << endl;
  cout << *(highScores + 1) << endl;
  cout << *(highScores + 2) << "\n\n";

  cout << "Increase score by passing array as a constant pointer.\n";
  increase(highScores, NUM_SCORES);

  cout << "Displaying scores by passing array as a constant pointer to a constant.\n";
  display(highScores, NUM_SCORES);

  return 0;
}

void increase(int* const array, const int NUM_ELEMENTS) {
  for(int i = 0; i < NUM_ELEMENTS; i++) {
    array[i] += 500;
  }
}

void display(const int* const array, const int NUM_ELEMENTS) {
  for(int i = 0; i < NUM_ELEMENTS; i++) {
    cout << array[i] << endl;
  }
}
