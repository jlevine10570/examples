#include <iostream>
class Base
{
        public:
        int x;
	~Base()
	{
		std::cout << " Base dtor \n";
	}
};

class Derived : public Base
{
        int xx;
	public:
	~Derived()
	{
		std::cout << " Derived dtor \n";
	}
};


Derived * testp()
{
	return new Derived;
}
	
int main( int x, char *v[])
{
	Base b;
	Derived *dptr;
	dptr = testp();
	b.x=3;
	delete dptr;
}
