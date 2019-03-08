----------------------------
unsigned int countSetBitsik(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}
----------------------------

# include<iostream> 
using namespace std; 
/* Function to get sum of digits */
class gfg 
{ 
    public: 
    int getSum(int n) 
    {  
    int sum = 0; 
    while (n != 0) 
    { 
     sum = sum + n % 10; 
     n = n/10; 
    }  
 return sum; 
 } 
----------------------------

#include <iostream>
 
struct Mammalia {};
struct Aves {};
 
struct Cat { using biological_class = Mammalia; };
struct Eagle { using biological_class = Aves; };
struct Dog { using biological_class = Mammalia; };
 
template <typename T>
/* we got rid of the m variable here as we dont need it */
void give_information(T t, Mammalia) {
    std::cout << "This animal belongs to the biological"
        << " class Mammalia" << std::endl;
}
 
template <typename T>
void give_information(T t, Aves) {
    std::cout << "This animal belongs to the biological"
        << " class Aves" << std::endl;
}
 
template <typename T>
void give_information(T t) {
    // let's just use this function to extract bio. class
    give_information(t, typename T::biological_class{});
}
----------------- 

