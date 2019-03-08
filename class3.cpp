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
	void f(int &x)
	{
		std::cout << "x is " << x <<'\n';
		g(x);
		std::cout << "x is " << x <<'\n';
	}
	void g(int &x)
	{
		x=0;
		std::cout << "x is " << x <<'\n';
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

	Derived d;
	int xx=123;
	d.f(xx);
	delete dptr;
}
