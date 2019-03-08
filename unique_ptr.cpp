#include <cassert>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct A {
  int z = 100;
  ~A() { std::cout << " Called the dtor\n"; }
};

unique_ptr<A> myFun() {
  unique_ptr<A> pa(new A());
  unique_ptr<A> pb;
  // nope !! unique_ptr<A> px = pa;
  // pb = std::move(pa);
  return pa;
}
A *myFunP() {
  auto pa = new A();
  return pa;
}

void xxxX( unique_ptr<A> up ) // this will not work 
{
  std::cout << up->z << "\n";
}
void xxx( unique_ptr<A> &up ) // this will  work 
{
  std::cout << up->z << "\n";
}


int main() {
  unique_ptr<A> au = myFun();  
  unique_ptr<A> ab;
  unique_ptr<A> ac;

  xxx(ac);
  const A &rA = *myFun();  // nope ! bad idea
  std::cout << rA.z << "\n";

  const A arA = *myFunP(); // nope ! bad idea
  std::cout << arA.z << "\n";

  std::cout << "Now exit()"<< "\n";
  // const auto rA1 &  = myFun();
   ab  = myFun();
   // this will not work ->>  ac = ab;
  // std::cout << rA1->z << "\n";
}
