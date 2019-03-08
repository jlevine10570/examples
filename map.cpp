#include <string>
#include <iostream>
#include <map>
 
    std::map<std::string,int> example ;
    std::map<std::string,int> example2 ;

void f(const std::string & w)
{  
 
    auto search = example.find(w);
    if (search != example.end()) {
        search->second++;
    } else {
        example.insert(std::pair<std::string,int>(w,1));
    }
}
void g(const std::string & w)
{  
 
        example2[w]++;
}
int main()
{
example[std::string("ONE")] = 1;
example2[std::string("ONE")] = 1;
f(std::string("TWO"));
g(std::string("TWO"));
std::cout << " Map sizes " << example.size() << " " << example2.size() << std::endl;
}

