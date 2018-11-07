#include <unistd.h>

#include <iostream>
using namespace std;

class A {
public:
  A() { std::cout << " def ctro for A \n"; }
  A(int ii) : i(ii) {}
  void show() { cout << "A.show() i = " << i << endl; }
  void operator()() { std::cout << " No op \n"; }

private:
  int i;
};

class B {
public:
  explicit B(int xx) : x(xx) { std::cout << " Call B ctor \n"; }
  operator A() const {
    std::cout << " Call conversion operator A () \n";
    return A(x);
  }

private:
  int x;
};

void g(A a) { a.show(); }

int main() 
{
  int i = 0; 
  for (i = 0; i < 10; i++) {
    int z = i;
    std::cout << "Loop < " << z << " \n";
    A a;
    z = 10;
  }
  return 0;
}
