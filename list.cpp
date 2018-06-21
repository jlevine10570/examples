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
#include "list.hpp"

void t1();


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
 List <std::array<int,12>> _items  {1,1,2,1,1,1,1,1,1,1,1,1,1};
 std::cout << _items.size() << "?\n";

	What<std::array<int,5>>();

	//std::array < int ,5> stdArr  { 1, 2, 3, 4, 5 };
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
	//int x = std::get<0>(mar2);
	t1();
	List<std::vector<int>> v =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = v.acc(0);
	std::cout << "Sum (accumulate) " << sum << '\n';
	sum = v.acc();
	std::cout << "Sum (accumulate) " << sum << '\n';
	std::cout << '\n';
	int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
	std::cout << "Product  " << product<< '\n';
	product = v.acc(v.begin(), v.end(), 1, std::multiplies<>());
	product = v.acc(v.begin(), v.end(), 1, std::plus<>());
	std::cout << "sum " << product<< '\n';
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
