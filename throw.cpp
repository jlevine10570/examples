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
		std::cout << " Derived dtor " << xx << '\n';
	}
	public:
	void add()
	{
		++xx;
	}
	
};


Derived * testp()
{
	return new Derived;
}

void testt()
{
	try
  {
	  Derived d;
	  d.add();
	  d.add();
	  d.add();

    throw 20;
  }
  catch (int e)
  {
     std::cout << "An exception occurred. Exception Nr. " << e << '\n';
  }
}
	
	
int main( int x, char *v[])
{
	testt();
}
