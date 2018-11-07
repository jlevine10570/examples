#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <functional>
#include <sstream>


std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& v)
{
    os << " -----\n" ;
    for ( auto& s : v )
        os << s << '\n' ;

    return os << " -----\n" ;
}

class StringGenerator
{
public:
    StringGenerator() : _engine(std::random_device()()), _dist('a', 'z') {}

    std::string operator()()
    {
        std::ostringstream result ;
        for ( unsigned i=0; i<4; ++i )
        {
            result << static_cast<char>(_dist(_engine)) ;
        }

        result << " (" << _stringNumber++ << ")" ;

        return result.str() ;
    }

private:
    std::mt19937 _engine ;
    std::uniform_int_distribution<unsigned> _dist ;

    static unsigned _stringNumber ;
};

unsigned StringGenerator::_stringNumber = 1 ;


struct descending 
{
    bool operator()(const std::string& a, const std::string& b) const
    {                                                          
        return a > b ;
    }
};

struct byNum
{
    bool operator()(const std::string& a, const std::string& b) const
    {                                                            
        unsigned aNum, bNum ;
        char dummy ;
        std::istringstream(a.substr(a.find('(')+1)+ b.substr(b.find('(')+1)) 
            >> aNum >> dummy >> bNum ;
        return aNum < bNum ;
    }
};

void ignoreLine(std::istream& is)
{
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
}

int main()
{
    StringGenerator gen ;
    std::vector<std::string> strings(25) ;
    std::generate(strings.begin(), strings.end(), StringGenerator()) ;

    std::cout << "Sorted in ascending order\n" ;
    std::sort(strings.begin(), strings.end()) ;
    std::cout << strings ;
    ignoreLine(std::cin) ;

    std::cout << "Sorted in descending order\n" ;
    std::sort(strings.begin(), strings.end(), descending()) ;
    std::cout << strings ;
    ignoreLine(std::cin) ;

    std::cout << "Sorted according to parenthetic value\n" ;
    std::sort(strings.begin(), strings.end(), byNum()) ;
    std::cout << strings ;
    gen();
    ignoreLine(std::cin) ;
}
