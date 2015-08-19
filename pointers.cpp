#include <iostream>
#include <string>

using namespace std;

int main(int c, char** argv) {
  int* pAPointer;
  int* pScore = 0;

  int score = 100;
  pScore = &score;

  cout << "Assigning &score to pScore\n";
  cout << "&score is: " << &score << endl;
  cout << "pScore is: " << pScore << endl;
  cout << "score is: " << score << endl;
  cout << "*pScore is: " << *pScore << "\n\n";

  cout << "Adding 500 to *pScore\n";
  score += 500;
  cout << "score is: " << score << endl;
  cout << "*pScore is:" << *pScore << "\n\n";

  cout << "Assigning &newScore to pScore\n";
  int newScore = 5000;
  pScore = &newScore;
  cout << "&newScore is: " << &newScore << endl;
  cout << "pScore is: " << pScore << endl;
  cout << "newScore is: " << newScore << endl;
  cout << "*pScore is: " << *pScore << "\n\n";

  cout << "Assigning &str to pStr\n";
  string str = "score";
  string* pStr = &str;
  cout << "str is: " << str << endl;
  cout << "*pStr is: " << *pStr << endl;
  cout << "(*pStr).size() is: " << (*pStr).size() << endl;
  cout << "pStr->size() is: " << pStr->size() << "\n\n";

  return 0;
}
