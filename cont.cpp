// g++ -std=c++17 -pedantic
#include <iostream>
#include <vector>
#include <iterator>
#include <array>
#include <set>
#include <list>


class Conts
{
	private:
		std::list<int>    _list;
		std::vector<int>  _vector;
		std::set<int>     _set;
		std::array<int,5> _array;
	public:
		Conts ()  {;}
		Conts (std::initializer_list <int> init)
		{
			// _list.insert(init); error 
			_list.assign(init);

			// _vector.insert(init); error
			_vector.assign(init);

			_set.insert(init);
			// _set.assign(init); error

			// _array.assign(init); error
			// _array.insert(init); error
			int i=0;
			for ( auto x : init )
				_array[i++]=x;
		}

};
int main ()
{
	Conts x;
}
