#include <iostream>
#include <map>
#include <utility>

typedef std::pair<std::string,std::string> pair;

class Base
{
        public:
        int x;
};

class Derived : public Base
{
        int xx;
};
class D1: public Base
{
        int xxx;
};
class D2: public Base
{
        int xxxx;
};

Derived d;
D1 d1;
D2 d2;

int main()
{
	Derived &fd = d;
//std::map<std::string,Base &> mapRef  = { std::make_pair<std::string,Base &> (std::string("d"),d) };
auto z = std::make_pair<std::string,Base &> (std::string("d"),d); 

    std::map<pair,int> map =
    {
        { std::make_pair("C++", "C++14"), 2014 },
        { std::make_pair("C++", "C++17"), 2017 },
        { std::make_pair("Java", "Java 7"), 2011 },
        { std::make_pair("Java", "Java 8"), 2014 },
        { std::make_pair("C", "C11"), 2011 }
    };

    for (const auto &entry: map)
    {
        auto key_pair = entry.first;
        std::cout << "{" << key_pair.first << "," << key_pair.second << "}, "
                  << entry.second << '\n';
    }

    return 0;
}
