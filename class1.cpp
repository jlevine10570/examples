#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Base {
public:
  Base():x(100) { iam(); }
  virtual void iam() { puts(__PRETTY_FUNCTION__); }
  int x;
};

class Derived : public Base 
{
public:
	Derived() { iam();}
   void iam() override { puts(__PRETTY_FUNCTION__); } 
  int xx;
};

int main() {
       	Base b; 
       	Derived d;
       	Base &bb = d; 
	Base *bp  = new ( Base );
	
       	Base forceBase= d ; 
      
	std::cout << " bp->x is " << bp->x << '\n';
	bp->x = 10; 
	std::cout << " bp->x is " << bp->x << '\n';
	(*bp).x  = 50; 
	std::cout << " bp->x is " << bp->x << '\n';
	forceBase.iam();
}
