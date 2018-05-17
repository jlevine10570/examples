#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <functional>
using namespace std;

template < class T1 > void  What(T1 t) 
{ 
			puts (__PRETTY_FUNCTION__);
}
// Class template with two parameters
template < class T1, size_t N = 1 > class Bloom
{
	private:
		T1 a;
		static const int entries1 = 1024*2*2; 
		static const int entries2 = 1024*2*2*2*2;
		static const int entries3 = 1024*2*2*2*2*2;
		int _lines = N;
		int _totalEntries = 0;
		int _totalSize= 0;
		std::array < bool, N * entries1 > _table1;	
		std::array < bool, N * entries2 > _table2;	
		std::array < bool, N * entries3 > _table3;
		void construct ()
		{
			puts (__PRETTY_FUNCTION__);
			_table3.fill (false);
			_table2.fill (false);
			_table1.fill (false);

		}

	public:
		Bloom ()
		{
			this->construct ();
		}
		Bloom (T1 x, int lines):_lines (lines)
	        {
		this->construct ();
		puts (__PRETTY_FUNCTION__);
	        }

		void show ()
		{
			std::cout << "Total entries accepted: " << _totalEntries << " Total size: " << _totalSize << '\n';
			std::cout << "Table 1 usage " <<  std::count(_table1.begin(),_table1.end(),true) << " max " << _table1.size() << '\n';
			std::cout << "Table 2 usage " <<  std::count(_table2.begin(),_table2.end(),true) << " max "  << _table2.size() << '\n';
			std::cout << "Table 3 usage " <<  std::count(_table3.begin(),_table3.end(),true) << " max "  << _table3.size()  << std::endl;
		}
		bool check (T1 in)
		{
			return(this->insert (in, true)==1);
		}
		int insert (T1 in, bool check = false)
		{
			std::size_t h1 = std::hash < T1 > { } (in);
			auto t1 = h1 % _table1.size();
			auto t2 = h1 % _table2.size();
			auto t3 = h1 % _table3.size();
			if (!check)
			{
				_table1[t1] = true;
				_table2[t2] = true;
				_table3[t3] = true;
				_totalSize+= in.size();
				return ++_totalEntries;
			}
			else
			{
				//	      std::cout << " Check is looking for "<< in << std::endl;
				//	      std::cout << " T1 T2 T3 "<< _table1[t1] << " " << _table2[t2] << " " << _table3[t3] <<  std::endl;
				if( _table3[t3] && _table2[t2] && _table1[t1] )
					return 1;
				else
					return 0;
			}

		}
};

std::string random_string (size_t length)
{
	auto randchar =[]()->char {
		const char charset[] =
			"0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof (charset) - 1);
		return charset[rand () % max_index];
	};
	std::string str (length, 0);
	std::generate_n (str.begin (), length, randchar);
	return str;
}
	int
main ()
{
	// instantiation with float and int type
	Bloom < int >test;
	Bloom < std::string, 4 > test1;

	std::string z;
	for (int a = 0; a < 200000; a++)
	{
		z = random_string (a % 32 + 5);
		test1.insert (z);
		//if ( a%1000 == 0 ) test1.show();
	}
	test1.show ();
	if (test1.check (z) == true )
		std::cout << z << " - was found 1\n";
	else
		std::cout << z << " error \n";

	for (int a = 0; a < 50; a++)
	{
		z = random_string (a % 32 + 5);
		if (test1.check(z))
			std::cout << z << " - was found ! \n";
		else
			std::cout << z << " - was _NOT_ found \n";
	}

	std::vector familyMush  {"JeremyLevine","MarcyGrossman-Levine","DylanLevine","SydneyLevine","JacobLevine"};
	auto family = {"Jeremy  Levine","Marcy Grossman-Levine","Dylan Levine","Sydney Levine","Jacob Levine"};
	What(family);
	What(*family.begin());
	for( auto &zz:family)
	{
		if (test1.check(zz))
			std::cout << zz << " - was found !! \n";
		else
			std::cout << zz<< " - was _NOT_found !! \n";

	}
	for( auto zz:familyMush)
	{
		if (test1.check(zz))
			std::cout << zz << " - was found !! \n";
		else
			std::cout << zz<< " - was _NOT_found !! \n";

	}
	std::map<std::string,int> ids;
	std::cout << ids["sss"s] << '\n';
	ids["sss"s]  = 2;
	std::cout << ids["sss"s] << '\n';
	auto it = ids.find("sss"s);
	it ->second=22;
	std::cout << ids["sss"s] << '\n';
	exit (0);
}
