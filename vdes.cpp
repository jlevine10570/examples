#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <string.h>
class Base {
	private:
		int z;
public:
  ~Base() { std::cout << "Call Base::~Base() \n"; };
   virtual void ff(int x) { std::cout << x << " Base::ff\n"; } ;
   virtual void f(int x=9) { std::cout << x << " Base::f\n"; } ;
   void over(int &x) { std::cout << x << " Base::over\n"; } ;
   void clear() { 
	   memset(this,0,sizeof(*this));
   };
	   Base():z(10){;}
};

class Derived : public Base {
public:
   void over(int &x) { std::cout << x << " Derived::over\n"; } ;
   void ff(int x,char t) { std::cout << x << " Derived::ff\n"; } ;
   virtual void f(int x=5) { std::cout << x << " Derived::f\n"; } ;
  ~Derived() { std::cout << "Call Derived::~Derived() \n"; };
};

int main(int c, char *v[]) {
  int j=0;
  Derived *d = new Derived;
  d->over(j);
  d->f();

  Base *b = new Derived;
  b->over(j);
  b->f();

  b->clear(); // reall bad idea , to have this function 

  delete b; // Does not call Derived's destructor!
  std::cout << "  --  \n";
  delete d;
}
