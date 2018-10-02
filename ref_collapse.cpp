#include <functional>
#include <iostream>
#include <memory>
#include <vector>

template <class T> void goo(T &x)
{
std::cout << __PRETTY_FUNCTION__ << std::endl;
}
template <class T> void foo(T &&x)
{
std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
int j=10;
int i=10;
foo(123);
foo(&i);
foo(std::move(j));
foo(i);
}
