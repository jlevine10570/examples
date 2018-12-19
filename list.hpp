// g++ -std=c++17 -pedantic
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <array>
#include <set>
#include <functional>
#include <numeric>
#include <type_traits>
template < class T1 > void  What()
{
	puts (__PRETTY_FUNCTION__);
}




namespace is_stl_container_impl{
	template <typename T> struct is_stl_array:std::false_type{};
	template <typename T, std::size_t N> struct is_stl_array<std::array<T,N>>:std::true_type{};

	template <typename T> struct is_stl_set:std::false_type{};
	template <typename T> struct is_stl_set<std::set<T>>:std::true_type{}; // all I do is inheirt 
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
		static constexpr auto isStdArray =  is_stl_array<T>::value;
		static constexpr auto isStdSet   =  is_stl_set<T>::value;
		static constexpr auto isStdCont  =  !isStdSet && !isStdArray;
		List () = default;
		List (std::initializer_list <typename T::value_type> init) 
		{
			if constexpr (isStdSet)  this->insert(init);
			if constexpr (isStdCont) this->assign(init);

			if( isStdArray)
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
