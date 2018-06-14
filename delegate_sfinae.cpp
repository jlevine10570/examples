#include <iostream>



template <typename T> struct HasSize
{
	typedef char (& yes)[1]; 
	typedef char (& no)[2];

	template <typename C> static yes check(decltype(&C::size));
	template <typename> static no check(...);

	static bool const value = sizeof(check<T>(0)) == sizeof(yes); // Make a yes/no value , very screwy
};


template < typename Derived > class baseClass
{
	public:
		template <typename T> struct HasImplCode
		{
			typedef char (& yes)[1]; 
			typedef char (& no)[2];

			template <typename C> static yes check(decltype(&C::do_something_impl)); // SFINAE 
			// in some case this is not true
			template <typename> static no check(...);
			static bool const value = sizeof(check<T>(0)) == sizeof(yes);
			//
			// OR the newer way bellow 
                        //
			template <typename C> static std::true_type  isDerivedImpl(decltype(&C::do_something_impl)); 
			// in some case this is not true
			template <typename>   static std::false_type isDerivedImpl(...);
                        
			static bool const valueBool = sizeof(isDerivedImpl<T>(nullptr));
			static constexpr bool isDerived = sizeof(isDerivedImpl<T>(nullptr));
			
		};

		template < class T, bool HasImpl> class Runner 
		{ 
			public:
			void 	_run(T& obj){ obj.do_something_impl();}
		};
		template < class T> class Runner <T,false>
		{ 
			public:
			void 	_run(T& obj){this->do_something_impl();}
		};

		void do_my_something (Derived & obj)
		{
			Runner<Derived,HasImplCode<Derived>::valueBool> foo3;	
			Runner<Derived,HasImplCode<Derived>::isDerived> foo2;	
			Runner<Derived,HasImplCode<Derived>::value > foo1;	
			foo1._run(obj);
			foo2._run(obj);
			foo3._run(obj);
		}

		void do_something ()
		{
			static_cast < Derived * >(this)->do_something_impl (); // !!!!!!!!!!!!
		}
	private:
		//Derived *D;
		void do_something_impl ()
		{
			std::cout << "The base class\n";
			// Default implementation
		}
}; 

class Foo:public baseClass < Foo >

{
	public:
		void do_something_impl ()
		{ std::cout << "The dervied class\n";}
}; 

class Bar:public baseClass < Bar >
{
};
template < typename Derived > void use (baseClass < Derived > &b)
{
	b.do_something ();
}

template < typename Derived > void useMe (Derived  &b)
{
	b.do_my_something (b);
}


main ()
{
	Foo foo { }; 

	use (foo);
	useMe (foo);
	Bar bar;
	use (bar);
	useMe (bar);
	//std::cout << HasSort<int>::value <<std::endl;
	//	std::cout << HasSort<int>::stat <<std::endl;
	//	int vals[10];
	//	Runner<Foo> l;
	//	l.runIt(foo);
	//begin(vals);
}
