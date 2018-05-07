#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include <array>
#include <set>
#include <functional>
#include <numeric>
#include <type_traits>


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



template <class T> class Baked_Container:public T
{
	public:
		static constexpr auto isStdArry =  is_stl_array<T>::value;
		static constexpr auto isStdSet =  is_stl_set<T>::value;
		Baked_Container (std::initializer_list <typename T::value_type> init) 
		{

		  std::cout << "This is a set ? = " << isStdSet << std::endl;
			if constexpr (isStdSet)
				this->insert(init);
			else
			if constexpr (!isStdArry)
				this->assign(init);
			else
			{	
				int i=0;
				for ( auto x : init ) 
				 { this->operator[](i++)=x; }
			}
		}
		Baked_Container () = default;

		template < class Func > Func applyTo (Func f)
		{
			return (std::for_each (this->cbegin(), this->cend(),f));
		}


		template < class T1 > auto acc (T1 init)
		{
			return (std::accumulate(this->begin(), this->end(),init));
		}

		auto acc ()
		{
			return (_acc<typename T::value_type>());
		}

	private:
		template < class T2 > auto _acc ()
		{
			return (std::accumulate(this->begin(), this->end(),(T2) 0));
		}
};

void heaps()
{
				 std::vector<int> v = {3, 1, 4, 1, 5, 9}; 
 
    std::make_heap(v.begin(), v.end());
 
    std::cout << "heap:\t";
    for (const auto &i : v) {
        std::cout << i << ' ';
    }   
 
    std::sort_heap(v.begin(), v.end());
 
    std::cout << "\nsorted:\t";
    for (const auto &i : v) {                                                   
        std::cout << i << ' ';
    }   
    std::cout << '\n';}

int main ()
{
	struct Sum
	{
		Sum(): sum{0} { }
		void operator()(int n) { sum += n; }
		int sum;
	};

	Baked_Container <std::vector<int>> bvec = { 5, 4, 3, 2 }; 
	Baked_Container <std::array<std::string,5>> barry = { "Jeremy","Marcy","Jacob","Sydney","Dylan" };
	Baked_Container <std::set<int>> bset = { 10,11,12,13 };
  bset.insert(100);
	Baked_Container < std::list<int>> blist = { 7, 5, 16, 8 };
	std::cout << "----\n";

	Sum s = bvec.applyTo(Sum());
	std::cout << "1. " << s.sum << std::endl;
	s = blist.applyTo(Sum());
	std::cout << "2. " << s.sum << std::endl;
	s = bset.applyTo(Sum());
	std::cout << "3. " << s.sum << std::endl;

	bset.applyTo(myFunc<int>);
	std::cout << '\n';
	barry.applyTo(myFunc<std::string>);
	std::cout << '\n';


heaps();

}


