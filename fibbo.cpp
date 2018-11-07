#include <iostream>

int f(const int i )
{
 if ( i ==0 || i == 1 ) return i ;

return( f(i-1) + f(i-2) );
}

int fib(int n) 
{ 
  int a = 0, b = 1, c, i; 
  if( n == 0) 
    return a; 
  for (i = 2; i <= n; i++) 
  { 
     c = a + b; 
     a = b; 
     b = c; 
  } 
  return b; 
} 
  
template<int n>
struct fibonacci
{
  static constexpr int value = fibonacci<n-1>::value + fibonacci<n-2>::value;
};
template<>
struct fibonacci<0>
{
  static constexpr int value = 0;
};
template<>
struct fibonacci<1>
{
  static constexpr int value = 1;
};

int mainx()
{
	std::cout << " Template " << fibonacci<25>::value << std::endl;
    return 0;
}

int main()
{
std::cout << f(13) << '\n';
mainx();
}
