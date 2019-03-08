#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
using namespace std;

#include "TimeSeries.h"

int main (int c, char *v[])
{
	TimeSeries<int> T;

	 fstream file;
  file.open ("foo.txt");
  std::string word;
	  int w;
	  int z=1000000010;
    while (file >> z >> w) 
    { 
 T.addValue(z,w );
        cout << "Data " << z << " " << w << endl;
	
    } 
std::cout << T;
    auto Tnew = T.sample(500);
    std::cout << "-----\n";
    //std::cout << T;
    std::cout << Tnew;
}
