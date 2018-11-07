#include <unistd.h>

#include<iostream> 
using namespace std; 
 
class A {  
 public: 
    A(int ii = 0) : i(ii) {} 
    void show() { cout << "A.show() i = " << i << endl;} 
    void operator () (){ std::cout << " No op \n" ; }
 private: 
    int i; 
}; 
 
class B { 
 public: 
   explicit  B(int xx) : x(xx) {std::cout << " Call B ctor \n";} 
   operator A () const { std::cout << " Call conversion operator A () \n" ; return A(x); } 
 private: 
    int x; 
}; 
 
void g(A a) 
{  a.show(); } 
 
int main() { 
  A anA; 
  B b(10); 
  g(b); // Finds and calls A() 
  g(20); 
  anA();
  return 0; 
}
