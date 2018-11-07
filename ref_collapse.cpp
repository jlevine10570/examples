#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <type_traits>
using namespace std::string_literals;

template <class T> void foo(T &x,  std::string i )
{
std::cout << __PRETTY_FUNCTION__ << std::endl;
std::cout << i << std::endl;
}
template <class T> void foo(T *x, std::string i )
{
std::cout << __PRETTY_FUNCTION__ << std::endl;
std::cout << i << std::endl;
}
template <class T> void foo(T &&x, std::string i )
{
std::cout << __PRETTY_FUNCTION__ << std::endl;
std::cout << i << std::endl;
}

int main()
{
int j=10;
int i=10;
foo(123, "foo(123)"s);
foo(&i, "foo(&i)"s);
foo(std::move(j), "foo(std::move(j)"s);
foo(i,"foo(i)"s);
}
