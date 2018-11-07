// visit.cpp

#include <iostream>
#include <vector>
#include <typeinfo>
#include <type_traits>

#include <cassert>
#include <variant>
#include <functional>
using namespace std::string_literals;
class TV
{

public:
  void operator () (const int &X) const
  { }
  void operator () (const float &X) const 
  { }
  void operator ()(const long &X) const
  { }
  void operator ()(const char &X) const
  { }
  //      void operator() ( const  double &X) {}
  //      void operator() ( const  long long &X) {}
  template < typename T > void operator ()(const T & obj) const
  {
    std::cout << obj << " Defaulted\n";
  }
private:
  int _visted = 0;
};

int main ()
{

  std::variant<int, std::string> v;

  std::cout << std::endl;
  std::string (z);		//ughhh - Create a variable z 
  std::string { z};				//ughhhhhhhhhhhh creates an anon string based on z

  TV tv;

  std::cout << std::endl;

  // get the sum
  std::common_type < char, long, float, int, double, long long >::type res
  {
  };				// 4

  std::cout << "typeid(res).name(): " << typeid (res).name () << std::endl;

  //assert(std::holds_alternative<std::string>(v)); 
 v = "abc"s;
    std::cout << std::boolalpha
              << "variant holds int? "
              << std::holds_alternative<int>(v) << '\n'
              << "variant holds string? "
              << std::holds_alternative<std::string>(v) << '\n';


}
