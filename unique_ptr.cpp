#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

using namespace std;

struct A 
{
	int z=100;
};

unique_ptr<A> myFun()
{
	unique_ptr<A> pa(new A());
	return pa;
}
int main()
{
	const A& rA = *myFun(); // nope ! With out the next two lines the datas life time ends 
//const auto rA1   = myFun();
//std::cout << rA1->z << "\n";
	std::cout << rA.z << "\n";
}

