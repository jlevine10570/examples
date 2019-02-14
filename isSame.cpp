#include <iostream>
#include <utility>

template<class T, class U>
struct is_the_same : std::false_type {};
 
template<class T>
struct is_the_same<T, T> : std::true_type {};


template<class A, class B>
class TestSame
{
	public:
static constexpr auto xv = is_the_same<A,B>{};
		TestSame() {
	       if constexpr (xv)
	std::cout << " we are the same \n";
	       else
	std::cout << " we are _NOT_ the same \n";
		} 
		
};


 

class B 
{
private:
int x;
};
class D : public  B 
{
private:
int h;
};
int main(int c , char * v[])
{
       auto x = is_the_same<D,D>();

       if ( x )
	       std::cout<< "yes" << '\n';
       else

	       std::cout<< "no" << '\n';

TestSame<int,D> ts{};
}




