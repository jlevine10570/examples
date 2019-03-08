#include <vector>
#include <iostream>

int main( int c, const char *v[])
{
std::vector<int> vec;
vec.resize(4);
std::cout << vec.size() << '\n';
vec[0]=1;
vec[1]=1;
vec[3]=1;
//vec[5]=1; //really wrong but compiles 
std::cout << vec.size() << '\n';
//std::cout << vec[5] << '\n';

    std::vector<int> nums {1, 3, 5, 7};
 
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

