#include <iostream>
#include <memory>
#include <iterator>
#include <algorithm>
 
std::shared_ptr<int> return_shr_ptr()
{
	auto ret = std::make_shared<int>();
	*ret=101010;
	return ret;
}

int main()
{
auto z = return_shr_ptr();
auto x = z ; 
auto & zr = *return_shr_ptr();
std::cout << "Data in shared ptr is " << *z << '\n';
std::cout << "Data in shared ptr is " << *x << '\n';
std::cout << "Data in ref ptr is " << zr << '\n';
std::cout << "Use count  in shared ptr is " << z.use_count() << '\n';
std::cout << "--------------------------------------------\n";
*z=12345;
std::cout << "Data in shared ptr is " << *z << '\n';
std::cout << "Data in shared ptr is " << *x << '\n';
std::cout << "Data in ref ptr is " << zr << '\n';
std::cout << "Use count  in shared ptr is " << z.use_count() << '\n';
std::cout << "--------------------------------------------\n";
x=nullptr;
std::cout << "Data in shared ptr is " << *z << '\n';
std::cout << "Use count  in shared ptr is " << z.use_count() << '\n';
z=nullptr;
std::cout << "Use count  in shared ptr is " << z.use_count() << '\n';
std::cout << "Data in ref ptr is " << zr << '\n';

}
