#include <iostream>
class Vbase
{
	public:
		virtual ~Vbase(){}
		virtual void do_it() = 0;
};

class Cbase : public Vbase
{
	      public:
	      ~Cbase() 
	{
	std::cout << "Dtor Cbase--";
	}

        virtual void do_it()
	{
		std::cout << "Cbase(do_it)--";
	}
};

// Finally 
class Dec : public Vbase
{
	private:
		Vbase *_mVbasePtr;
	public:
		Dec(Vbase *input ):_mVbasePtr(input){;}
		~Dec(){ delete _mVbasePtr;}

		virtual void do_it()
		{
			_mVbasePtr->do_it();
		}
};

class option1 : public Dec 
{
	public:
		option1( Vbase *simple):Dec(simple){}
		~option1()
		{std::cout<< "option1 dtor--";}

		virtual void do_it()
		{
			Dec::do_it();
			std::cout << "option1(do_it)--";
		}
};
class option2 : public Dec 
{
	public:
		option2( Vbase *simple):Dec(simple){}
		~option2()
		{std::cout<< "option2 dtor--";}

		virtual void do_it()
		{
			Dec::do_it();
			std::cout << "option2(do_it)--";
		}
};
class option3 : public Dec 
{
	public:
		option3( Vbase *simple):Dec(simple){}
		~option3()
		{std::cout<< "option3 dtor--";}

		virtual void do_it()
		{
			Dec::do_it();
			std::cout << "option3(do_it)--";
		}
};

main()
{
Cbase *concrete = new(Cbase);
Vbase *concreteOp1 = new option1(new(Cbase));
Vbase *concreteOp1Op2 = new option2(new option1(new(Cbase)));
std::cout <<'\n';
concreteOp1Op2->do_it(); 
std::cout <<'\n';
delete concrete;
std::cout <<'\n';
delete concreteOp1;
std::cout <<'\n';
delete concreteOp1Op2;
std::cout <<'\n';
}

