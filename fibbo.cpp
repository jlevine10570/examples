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
  


int main()
{
std::cout << f(13) << '\n';
}
