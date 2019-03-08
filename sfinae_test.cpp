
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
class A {};
class B {
public:
  int a;
};
class C {
  void foo() { ; }
};

template <typename T, typename = void> struct test 
{
  test() { std::cout << "Using None" << std::endl; }
};

template <typename T> struct test<T, decltype(&T::a)> 
{
  test() { std::cout << "Using T::a" << std::endl; }
};

template <typename T> struct test<T, decltype(&T::foo)> 
{
  test() { std::cout << "Using T::foo" << std::endl; }
};


int main() {
  // call the test based on data memeber
  test<A> a;
  test<B> b;
  test<C> c;
}
