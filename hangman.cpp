#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

int randomWord(int i) {
  return rand() % i;
}

int main() {
  const int MAX_WRONG = 8;

  vector<string> words;
  words.push_back("GUESS");
  words.push_back("HANGMAN");
  words.push_back("DIFFICULT");

  srand(unsigned(time(0)));
  random_shuffle(words.begin(), words.end(), randomWord);
  const string THE_WORD = words[0];

  int wrong = 0;
  string soFar(THE_WORD.size(), '-');
  string used = "";

  cout << "\tWelcome to HANGMAN. Good luck!.\n\n";

  while((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
    cout << "You have " << (MAX_WRONG - wrong);
    cout << " Incorrects guesses left.\n";
    cout << "\nYou've used the following letters:\n" << used << endl;
    cout << "\nSo far, the word is: \n" << soFar << endl;

    char guess;
    cin >> guess;
    guess = toupper(guess);

    while(used.find(guess) != string::npos) {
      cout << "\nYou've already guessed" << endl;
      cout << "Enter your guess: ";
      cin >> guess;
      guess = toupper(guess);
    }

    used += guess;

    if(THE_WORD.find(guess) != string::npos) {
      cout << "That's right ! " << guess << " is the word\n";

      for(int i = 0; i <  THE_WORD.size(); i++) {
        if(THE_WORD[i] == guess) {
          soFar[i] = guess;
        }
      }
    } else {
      cout << "Sorry, " << guess << " isn't in the word.\n";
      ++wrong;
    }
  }

  if(wrong == MAX_WRONG) {
    cout << "\nYou have been hanged!";
  } else {
    cout << "\nYou guessed it!";
  }

  cout << "\nThe word was " << THE_WORD << endl;

}
