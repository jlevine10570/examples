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
  // nope !! unique_ptr<A> px = pa;
  return pa;
}
A *myFunP() {
  auto pa = new A();
  return pa;
}
int main() {
  unique_ptr<A> au = myFun();  
  unique_ptr<A> ab;

  const A &rA = *myFun();  // nope !
  std::cout << rA.z << "\n";
  const A arA = *myFunP(); // nope !
  std::cout << arA.z << "\n";
  std::cout << "Now exit()"<< "\n";
  // const auto rA1 &  = myFun();
  // std::cout << rA1->z << "\n";
}
