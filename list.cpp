#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <array>
#include <set>
#include <functional>
#include <numeric>
#include <type_traits>

void t1();
template < class T1 > void  What()
{
                        puts (__PRETTY_FUNCTION__);
}

template <> void  What<int>()
{
                        puts (__PRETTY_FUNCTION__);
}

namespace is_stl_container_impl{
	template <typename T>       struct is_stl_array:std::false_type{};
	template <typename T, std::size_t N> struct is_stl_array<std::array<T,N>>:std::true_type{};

	template <typename T> struct is_stl_set:std::false_type{};
	template <typename T> struct is_stl_set<std::set<T>>:std::true_type{};
}

template <typename T> struct is_stl_array {
	static constexpr bool const value = is_stl_container_impl::is_stl_array<std::decay_t<T>>::value;
};
template <typename T> struct is_stl_set {
	static constexpr bool const value = is_stl_container_impl::is_stl_set<std::decay_t<T>>::value;
};



template < class T> void myFunc (T i)
{				// function:
	std::cout << ' ' << i;
}

	void my_functionC (const std::string &i)
{				// function:
	std::cout << ' ' << i;
}

	void my_function (const int &i)
{				// function:
	std::cout << ' ' << i;
}

void myBad (int &i)
{				// function:
	i = i * 10;
	std::cout << ' ' << i;
}

template <class T> class List:public T
{
	public:
		static constexpr auto isStdArry =  is_stl_array<T>::value;
		static constexpr auto isStdSet =  is_stl_set<T>::value;

		List () = default;
		List (std::initializer_list <typename T::value_type> init) 
		{
			if constexpr (isStdSet)
				this->insert(init);
			else
				if constexpr (!isStdArry)
					this->assign(init);
				else
				{	
					int i=0;
					for ( auto x : init )
					{
						//std::cout << "i == " << i << " data = "<< x << '\n'; 
						this->operator[](i++)=x;

					}	
				}
		}

		template < class V > auto fill (V v)
		{
			return (std::fill(this->cbegin (), this->cend (), v));
		}
		template < class Func > bool allof (Func f)
		{
			return (std::all_of(this->cbegin (), this->cend (), f));
		}
		template < class InputIt , class Func > Func cspan (InputIt first, InputIt last,Func f)
		{
			return (std::for_each (first,last,f));
		}

		template < class Func > Func cspan (Func f)
		{
			return (std::for_each (this->cbegin (), this->cend (), f));
		}
		template < class Func > Func span (Func f)
		{
			return (std::for_each (this->begin (), this->end (), f));
		}
		template < class Func > Func cspan (int n, Func f)
		{
			if (n < 0) n = 0;
			auto xx = this->cbegin ();
			std::advance (xx, n);
			return (std::for_each (xx, this->cend (), f));
		}
		template < class Func > Func cspan (Func f, int n)
		{
			if (n > 0) n = 0;
			auto xx = this->cend ();
			std::advance (xx, n);
			return (std::for_each (this->cbegin (), xx, f));
		}

		template < class Func > Func cspan (size_t s, int e ,Func f)
		{
			if (e > 0) e = 0;
			auto ss = this->cbegin ();
			auto ee = this->cend ();
			std::advance (ss, s);
			std::advance (ee, e);
			return (std::for_each (ss, ee, f));

		}
		template < class InputIt, class OutputIt, class Func> 
			auto tform (InputIt first1, InputIt last1, OutputIt d_firs,Func f)
			{
				return (std::transform(first1, last1,d_firs, f));
			}
		template < class Func > auto tform (Func f)
		{
			return (std::transform(this->begin(), this->end(),this->begin(), f));
		}
		template < class T1 > auto acc (T1 init)
		{
			return (std::accumulate(this->begin(), this->end(),init));
		}
		template < class T1, class Func  > auto acc (T1 init, Func f)
		{
			return (std::accumulate(this->begin(), this->end(),init,f));
		}
		template < class IIt, class T1, class Func> auto acc ( IIt first,IIt last,T1 init,Func f)
		{
			return (std::accumulate(first,last,init,f));
		}
		auto acc ()
		{
			return (_acc<typename T::value_type>());
		}
		auto print()
		{
			for(auto i: *this)
				std::cout<<"----" << i << '\n'; 
			//return (_print<typename T::value_type>());
			std::cout  << '\n' ;
		}

	private:
		template < class T2 > void  _print ()
		{ 
			for(auto i: *this){;}
		}
		template < class T2 > auto _acc ()
		{
			What<T2>();
			return (std::accumulate(this->begin(), this->end(),(T2) 0));
		}
};

struct Sum
{
	Sum (): _sum { 0} { }
	int _sum;
	void
		operator () (int n)
		{ _sum += n;}
};
int main ()
{
	List <std::vector<int>> mList = { 5, 4, 3, 2 }; //
	List <std::array<std::string,5>> marray = { "Jeremy","Marcy","Jacob","Sydney","Dylan" }; //
	marray.span(my_functionC);
	std::cout << '\n';

	What<std::array<int,5>>();

	std::array < int ,5> stdArr  { 1, 2, 3, 4, 5 };
	std::set < int > stdSet  { 1, 2, 3, 4, 5 };

	mList.push_back (1);
	List <std::vector<int>> mList1;
	mList1.push_back (1);
	//mList1.span(my_function);
	//std::cout << '\n';

	std::cout << "\n Test -- > \n";
	for_each (mList.begin (), mList.end (), my_function);
	std::cout <<'\n';
	auto xx = mList.begin ();
	std::advance (xx, 2);
	std::cout <<'\n';
	mList.cspan (mList.begin (), mList.end (),my_function);
	std::cout <<'\n';
	mList.cspan (xx, mList.end (),my_function);
	std::cout <<'\n';
	mList.cspan (my_function);
	std::cout << "\n Test end\n ";
#if 0 
	std::cout << "\n Start 3 in -- > ";
	mList.cspan (3, my_function);
	std::cout << "\n";
	std::cout << "\n End 3 back -- > ";
	mList.cspan (my_function, -3);
	std::cout << '\n';
	std::cout << "\n Start 2 in end 2 back -- > ";
	mList.cspan (2,-2, my_function);
	std::cout << '\n';
	mList.span (myBad);
#endif 
	///////////////////////////////

	std::cout << is_stl_array<std::array<int,4>>::value << '\n';
	auto add_lambda = [](auto first, auto second) { return first + second; };
	std::array<int,2> arr2 = { 1,2};
	std::vector<int> vec2 = { 1,2};
	List <std::array<int,2>> mar2 = { 500,500 }; //
	std::cout << "add lambda " << std::apply(add_lambda,arr2);
	std::cout << "add lambda " << mar2[0];
	int x = std::get<0>(mar2);
	t1();
	List<std::vector<int>> v =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = v.acc(0);
	std::cout << "Sum (accumulate) " << sum << '\n';
	sum = v.acc();
	std::cout << "Sum (accumulate) " << sum << '\n';
	std::cout << '\n';
	int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
	std::cout << "Product  " << product<< '\n';
	product = v.acc(v.begin(), v.end(), 1, std::multiplies<int>());
	std::cout << "Product  " << product<< '\n';
	product = v.acc( 1, std::multiplies<int>());
	std::cout << "Product  " << product<< '\n';
	v.print();
	mar2.print();
	if (v.allof( [](int i){ return i > 0 ; })) 
	{
		std::cout << " all of\n ";
       	         v.print() ;
		 std::cout << " greater then 0 \n";
	}
	return 0; 
}

void t1()
{
	std::cout << '\n';
	List <std::array<char,5>> s = { 'h','e','l','l','o' }; //
	std::transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c) -> unsigned char { return std::toupper(c); });

	std::vector<std::size_t> ordinals;
	std::transform(s.begin(), s.end(), std::back_inserter(ordinals),
			[](unsigned char c) -> std::size_t { return c; });


	for (auto ord : ordinals) {
		std::cout << ' ' << ord;
	}

	s.span(myFunc<char>);
	std::cout << '\n';
	List <std::array<char,5>> ss = { 'h','e','l','l','o' }; //
	List <std::array<char,5>> ss1 = { 'h','e','l','l','o' }; //
	ss.tform( [](unsigned char c) -> unsigned char { return std::toupper(c); });
	ss.tform( ss1.begin(),ss1.end(),ss1.begin(),
			[](unsigned char c) -> unsigned char { return std::toupper(c); });
	//ss.tform( myFunc<char>);
	ss.span(myFunc<char>);
	std::cout << '\n';
	ss1.span(myFunc<char>);
	std::cout << '\n';
}
