
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
class A {};
class B{ int a;};

template<typename, typename = void>
struct test
{ test(){std::cout<< "Using None" <<std::endl;} };

template<typename T>
struct test<T, decltype(&T::a)>
{ test(){std::cout<< "Using T::a" <<std::endl;} };

int main()
{
       	test<A> a; 
       	test<B> b; 
}
