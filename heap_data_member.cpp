#include <iostream>
#include <string>

using namespace std;

class Critter {
public:
  Critter(const string& name = "", int age = 0);
  ~Critter();
  Critter(const Critter& c);
  Critter& operator=(const Critter& c);
  void greet() const;

private:
  string* m_pName;
  int m_age;
};

Critter::Critter(const string& name, int age) {
  cout << "Constructor called.\n";
  m_pName = new string(name);
  m_age = age;
}

Critter::~Critter() {
  cout << "Desctructor called\n";
  delete m_pName;
}

Critter::Critter(const Critter& c) {
  cout << "Copy Constructor called\n";
  m_pName = new string(*(c.m_pName));
  m_age = c.m_age;
}

Critter& Critter::operator=(const Critter& c) {
  cout << "Overloaded assignment operator called.\n";
  if(this != &c) {
    delete m_pName;
    m_pName = new string(*(c.m_pName));
    m_age = c.m_age;
  }

  return *this;
}

void Critter::greet() const {
  cout << "I'm " << *m_pName << " and I'm " << m_age << " years old.\n";
  cout << "&m_pName: " << cout << &m_pName << endl;
}

void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

int main() {
  testDestructor();
  cout << endl;

  Critter c("Poochie", 5);
  c.greet();
  testCopyConstructor(c);
  c.greet();
  cout << endl;

  testAssignmentOp();

  return 0;
}

void testDestructor() {
  Critter toDestroy("rover", 3);
  toDestroy.greet();
}

void testCopyConstructor(Critter aCopy) {
  aCopy.greet();
}

void testAssignmentOp() {
  Critter c1("c1", 7);
  Critter c2("c2", 9);

  c1 = c2;

  c1.greet();
  c2.greet();

  Critter c3("c3", 11);
  c3 = c3;
  c3.greet();
}
