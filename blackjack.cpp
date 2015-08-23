#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Card {
public:
  enum rank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
  enum suit {CLUBS, DIAMONDS, HEARTS, SPACEDS};

  friend ostream& operator<<(ostream& os, const Card& aCard);

  Card(rank r = ACE, suit s = SPACEDS, bool ifu = true);
  int getValue() const;
  void flip();

private:
  rank m_rank;
  suit m_suit;
  bool m_isFaceUp;
};

Card::Card(rank r, suit s, bool ifu):
m_rank(r),
m_suit(s),
m_isFaceUp(ifu) {}

int Card::getValue() const {
  int value = 0;
  if(m_isFaceUp) {
    value = m_rank;

    if(value > 10) {
      value = 10;
    }
  }

  return value;
}

void Card::flip() {
  m_isFaceUp = !(m_isFaceUp);
}


class Hand {
public:
  Hand();
  virtual ~Hand();
  void add(Card* pCard);
  void clear();
  int getTotal() const;

protected:
  vector<Card*> m_cards;
};

Hand::Hand() {
  m_cards.reserve(7);
}

Hand::~Hand(){
  clear();
}

void Hand::add(Card* card) {
  m_cards.push_back(card);
}

void Hand::clear() {
  vector<Card*>::iterator iter = m_cards.begin();

  for(iter = m_cards.begin(); iter != m_cards.end(); iter++) {
    delete *iter;
    *iter = 0;
  }

  m_cards.clear();
}

int Hand::getTotal() const {
  if(m_cards.empty()) {
    return 0;
  }

  if(m_cards[0]->getValue() == 0) {
    return 0;
  }

  int total = 0;
  vector<Card*>::const_iterator iter;

  for(iter = m_cards.begin(); iter != m_cards.end(); iter++) {
    total += (*iter)->getValue();
  }

  bool containsAce = false;
  for(iter = m_cards.begin(); iter != m_cards.end(); iter++) {
    if((*iter)->getValue() == Card::ACE) {
      containsAce = true;
    }
  }

  if(containsAce && total <= 10) {
    total += 10;
  }

  return total;
}


class GenericPlayer : public Hand {
  friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
  GenericPlayer(const string& name = "");
  virtual ~GenericPlayer();
  virtual bool isHitting() const = 0;
  bool isBusted() const;
  void bust() const;

protected:
  string m_name;
};

GenericPlayer::GenericPlayer(const string& name):
m_name(name) {

}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::isBusted() const {
  return (getTotal() > 21);
}

void GenericPlayer::bust() const {
  cout << m_name << " bust.\n";
}

class Player : public GenericPlayer {
public:
  Player(const string& name = "");
  virtual ~Player();
  virtual bool isHitting() const;
  void win() const;
  void lose() const;
  void push() const;
};

Player::Player(const string& name):
GenericPlayer(name){}

Player::~Player(){}

bool Player::isHitting() const {
  cout << m_name << ", do you want a hit?(y/n): ";
  char response;
  cin >> response;

  return (response == 'y' || response == 'Y');
}

void Player::win() const {
  cout << m_name << " wins.\n";
}

void Player::lose() const {
  cout << m_name << " lose.\n";
}

void Player::push() const {
  cout << m_name << " pushes.\n";
}

class House : public GenericPlayer{
public:
  House(const string& name = "House");
  virtual ~House();
  virtual bool isHitting() const;
  void flipFirstCard();
};

House::House(const string& name):
GenericPlayer(name){}

House::~House() {}

bool House::isHitting() const {
  return (getTotal() <= 16);
}

void House::flipFirstCard() {
  if(!(m_cards.empty())) {
    m_cards[0]->flip();
  } else {
    cout << "No card to flip!.\n";
  }
}

class Deck : public Hand {
public:
  Deck();
  virtual ~Deck();
  void populate();
  void shuffle();
  void deal(Hand& aHand);
  void additionalCards(GenericPlayer& aGenericPlayer);
};

Deck::Deck() {
  m_cards.reserve(52);
  populate();
}

Deck::~Deck(){}

void Deck::populate() {
  clear();
  for(int s = Card::CLUBS; s <= Card::SPACEDS; s++) {
    for(int r = Card::ACE; r <= Card::KING; r++) {
      add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
    }
  }
}

void Deck::shuffle() {
  random_shuffle(m_cards.begin(), m_cards.end());
}

void Deck::deal(Hand& aHand) {
  if(m_cards.empty()) {
    aHand.add(m_cards.back());
    m_cards.pop_back();
  } else {
    cout << "Out of cards. Unable to deal.";
  }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer) {
  cout << endl;
  while(!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting()) {
    deal(aGenericPlayer);
    cout << aGenericPlayer << endl;

    if(aGenericPlayer.isBusted()) {
      aGenericPlayer.bust();
    }
  }
}

class Game {
public:
  Game(const vector<string>& names);
  ~Game();
  void play();

private:
  Deck m_deck;
  House m_house;
  vector<Player> m_players;
};

Game::Game(const vector<string>& names) {
  vector<string>::const_iterator pName;
  for(pName = names.begin(); pName != names.end(); pName++) {
    m_players.push_back(Player(*pName));
  }

  srand(static_cast<unsigned int>(time(0)));
  m_deck.populate();
  m_deck.shuffle();
}

Game::~Game() {}

void Game::play() {
  vector<Player>::iterator pPlayer;

  for(int i = 0; i < 2; i++) {
    for(pPlayer = m_players.begin(); pPlayer != m_players.end(); pPlayer++) {
      m_deck.deal(*pPlayer);
    }
    m_deck.deal(m_house);
  }

  m_house.flipFirstCard();

  for(pPlayer = m_players.begin(); pPlayer != m_players.end(); pPlayer++) {
    cout << *pPlayer << endl;
  }
  cout << m_house << endl;

  for(pPlayer = m_players.begin(); pPlayer != m_players.end(); pPlayer++) {
    m_deck.additionalCards(*pPlayer);
  }

  m_house.flipFirstCard();
  cout << endl << m_house;

  m_deck.additionalCards(m_house);

  if(m_house.isBusted()) {
    for(pPlayer = m_players.begin(); pPlayer != m_players.end(); pPlayer++) {
      if(!(pPlayer->isBusted())) {
        pPlayer->win();
      }
    }
  } else {
    for(pPlayer = m_players.begin(); pPlayer != m_players.end(); pPlayer++) {
      if(!(pPlayer->isBusted())) {
        if(pPlayer->getTotal() > m_house.getTotal()) {
          pPlayer->win();
        } else if(pPlayer->getTotal() < m_house.getTotal()) {
          pPlayer->lose();
        } else {
          pPlayer->push();
        }
      }
    }
  }

  for(pPlayer = m_players.begin(); pPlayer != m_players.end(); pPlayer++) {
    pPlayer->clear();
  }

  m_house.clear();
}

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer);

int main() {
  cout << "\t\t**Welcome to Blackjack**\n\n";

  int numPlayers = 0;
  while (numPlayers < 1 || numPlayers > 7) {
    cout << "How many players? (1 - 7): ";
    cin >> numPlayers;
  }

  vector<string> names;
  string name;
  for(int i = 0; i < numPlayers; i++) {
    cout << "Enter player name: ";
    cin >> name;
    names.push_back(name);
  }

  cout << endl;

  Game aGame(names);
  char again = 'y';
  while(again != 'n' && again != 'N') {
    aGame.play();
    cout << "\nDo you want to play again? (Y/N): ";
    cin >> again;
  }

  return 0;
}

ostream& operator<<(ostream& os, const Card& aCard) {
  const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K"};
  const string SUITS[] = {"c", "d", "h", "s"};

  if(aCard.m_isFaceUp) {
    os << RANKS[aCard.m_rank] << SUITS[aCard.m_suit];
  } else {
    os << "XX";
  }

  return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) {
  os << aGenericPlayer.m_name << ":\t";
  vector<Card*>::const_iterator pCard;
  if(!aGenericPlayer.m_cards.empty()) {
    for(pCard = aGenericPlayer.m_cards.begin(); pCard != aGenericPlayer.m_cards.end(); pCard++) {
      os << *(*pCard) << "\t";
    }

    if(aGenericPlayer.getTotal() != 0) {
      cout << "(" << aGenericPlayer.getTotal() << ")";
    }
  } else {
    os << "<empty>";
  }
  return os;
}
