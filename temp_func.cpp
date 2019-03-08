#include <iostream>
#include <cmath>
template <typename T>
T power ( T a, T b) {
 return (std::pow(a,b));
}

template <>
int  power ( int  a, int  b) {
 return (std::pow(a,b));
}



int main()
{
std::cout << power<int >(10,2) << "\n";;
}
