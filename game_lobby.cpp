#include <iostream>
#include <string>

using namespace std;

class Player {
public:
  Player(const string& name = "");
  string getName() const;
  Player* getNext() const;
  void setNext(Player* next);

private:
  string m_name;
  Player* m_pNext;
};

Player::Player(const string& name):
m_name(name),
m_pNext(0) {

}

string Player::getName() const {
  return m_name;
}

Player* Player::getNext() const {
  return m_pNext;
}

void Player::setNext(Player* next) {
  m_pNext = next;
}

class Lobby {
  friend ostream& operator<<(ostream& os, const Lobby& aLobby);

public:
  Lobby();
  ~Lobby();
  void addPlayer();
  void removePlayer();
  void clear();

private:
  Player* m_pHead;
};

Lobby::Lobby():
m_pHead(0) {}

Lobby::~Lobby() {
  clear();
}

void Lobby::addPlayer() {
  cout << "Please enter the name of the new Player: ";
  string name;
  cin >> name;
  Player* pNewPlayer = new Player(name);

  if(m_pHead == 0) {
    m_pHead = pNewPlayer;
  } else {
    Player* pIter = m_pHead;
    while(pIter->getNext() != 0) {
      pIter = pIter->getNext();
    }
    pIter->setNext(pNewPlayer);
  }
}

void Lobby::removePlayer() {
  if(m_pHead == 0) {
    cout << "The game lobby is empty. no one to remove.\n";
  } else {
    Player* pTemp = m_pHead;
    m_pHead = m_pHead->getNext();
    delete pTemp;
  }
}

void Lobby::clear() {
  while(m_pHead != 0) {
    removePlayer();
  }
}

ostream& operator<<(ostream& os, const Lobby& aLobby) {
  Player* pIter = aLobby.m_pHead;
  os << "\nHere's who's in the game lobby:\n";

  if(pIter == 0) {
    os << "The lobby is empty.\n";
  } else {
    while(pIter != 0) {
      os << pIter->getName() << endl;
      pIter = pIter->getNext();
    }
  }

  return os;
}

int main() {
  Lobby myLobby;
  int choice;

  do {
    cout << myLobby;
    cout << "\nGAME LOBBY\n";
    cout << "0 - Exit the program.\n";
    cout << "1 - Add a player to the lobby.\n";
    cout << "2 - Remove a player from the lobby.\n";
    cout << "3 - Clear the lobby.\n";
    cout << endl << "Enter choice: ";
    cin >> choice;

    switch(choice) {
      case 0: cout << "Good bye.\n"; break;
      case 1: myLobby.addPlayer(); break;
      case 2: myLobby.removePlayer(); break;
      case 3: myLobby.clear(); break;
      default: cout << "That was not a valid choice.\n";
    }
  } while(choice != 0);

  return 0;
}
