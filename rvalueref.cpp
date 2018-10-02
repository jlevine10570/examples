#include <functional>
#include <iostream>
#include <iostream>
#include <memory>
#include <vector>
class Z {
private:
  int _x;

public:
  Z() : _x(1) { ; }

  int get() { return _x; };
};

int f(Z &x) { std::cout << " In ref \n"; }
int f(Z &&x) {
  std::cout << " In ref ref \n";
  f(x);
}
int main() {
  Z z, x;
  f(z); // Should call ref
  std::cout << "--------------------\n";
  f(Z{}); // Should call ref ref , the call  ref
  std::cout << "--------------------\n";
  f(std::move(z)); // Should call ref ref , the call  ref
}
