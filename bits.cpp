// C++ program to Count set 
// bits in an integer  
#include <bits/stdc++.h>      
using namespace std; 
  
/* Function to get no of set bits in binary 
representation of positive integer n */
unsigned int countSetBits(unsigned int n) 
{ 
unsigned int count = 0; 
while (n) 
{ 
    count += n & 1; 
    n >>= 1; 
} 
return count; 
} 

unsigned int countSetBitsk(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

/* Program to test function countSetBits */
int main() 
{ 
    int i = 161; 
    cout << '\n'<< countSetBitsk(i); 
    return 0; 
} 
