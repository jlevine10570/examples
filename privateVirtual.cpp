
#include <iostream>
using namespace std;

class Derived;

class Base {
private:
  int z = 0;
  virtual void fun() { cout << "Base Fun"; }
  friend int main();
};

class Derived : public Base {
public:
  void fun() { cout << "Derived Fun\n"; }
};

int main() {
  Base *ptr = new Derived;
  ptr->fun();
  return 0;
}
