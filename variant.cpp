// visit.cpp

#include <iostream>
#include <vector>
#include <typeinfo>
#include <type_traits>

#include <variant>
#include <functional>

  template <auto v>
struct integral_constant
{
   static constexpr auto value = v;
};

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

  std::cout << std::endl;
  std::string (z);		//ughhh
  std::string { z};				//ughhhhhhhhhhhh

  auto v1 =[](auto && arg)
  {
    std::cout << typeid (arg).name () << " ";
  };

  std::vector < std::variant < char, long, float, int, double, long long >>	// 1
    vecVariant = { 5, '2', 5.4, 100ll, 2011l, 3.5f, 2017};

  TV tv;
  // noop
for (auto & v:vecVariant)
    {
      std::visit (tv, v);
      // 3
    }

  std::cout << std::endl;
  //
  // display each value                                                             
for (auto & v:vecVariant) { std::visit ([](auto && arg) { std::cout << arg << " "; } , v);}		// 2 

  std::cout << std::endl;

  // display each type
for (auto & v:vecVariant)
    {
      std::visit (v1, v);
      // 3
    }

  std::cout << std::endl;

  // get the sum
  std::common_type < char, long, float, int, double, long long >::type res
  {
  };				// 4

  std::cout << "typeid(res).name(): " << typeid (res).name () << std::endl;

for (auto & v:vecVariant)
    {
      std::visit ([&res] (auto && arg) { res += arg; } , v);		// 5
    }
  std::cout << "res: " << res << std::endl;

  // double each value
for (auto & v:vecVariant)
    {
      std::visit ([&res] (auto && arg) { arg *= 2;} , v);		// 6
      std::visit ([](auto && arg) { std::cout << arg << " ";} , v);
    }

  std::cout << std::endl;
 //integral_constant<2048>::value; integral_constant<'a'>::value;
  std::variant < char, long, float, int, double, long long > vx;
  vx=(float)2.33;
  std::cout << "Which member of variant in in place " << vx.index() << std::endl;
     std::cout << std::boolalpha
              << "variant holds double? "
              << std::holds_alternative<double>(vx) << '\n';
  //std::count <<std::boolalpha <<  "Does the variant hold a double " << std::holds_alternative<double>(vx) << std::endl


 std::variant<int, std::string> v = "abc";
    std::cout << std::boolalpha
              << "variant holds int? "
              << std::holds_alternative<int>(v) << '\n'
              << "variant holds string? "
              << std::holds_alternative<std::string>(v) << '\n';

}
