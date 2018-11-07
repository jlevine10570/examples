#include "isDerived.hpp"
#include <iostream>

class Base 
{
	public:
	int x;
};

class Derived : public Base
{
	int xx;
};

int main( int c, char *v[])
{

	if ( std::is_base_of<Base,Derived>() == true )
		std::cout << "Is derieved \n";
	else
		std::cout << "Is not derieved \n";

	if ( IsDerivedFrom<Derived,Base>() == true )
		std::cout << "Is derieved \n";
	else
		std::cout << "Is not derieved \n";

	if ( IsDerivedFrom<Base,Derived>() == true )
		std::cout << "Is derieved \n";
	else
		std::cout << "Is not derieved \n";

	return 0;
}
