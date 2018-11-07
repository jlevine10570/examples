#include <iostream>
#include <utility>
template < class T1 > void  What()
{
        puts (__PRETTY_FUNCTION__);
}

class B 
{
private:
int x;
};
class D : public  B 
{
private:
int h;
};


 template < typename Base, typename PotentialDerived >
struct IsDerivedFrom
{
  typedef char (&no)  [1];
  typedef char (&yes) [2];

  static yes check(Base*);
  static no  check(...);
  static constexpr std::true_type Tcheck(Base*){ return std::true_type{};} 
  static constexpr std::false_type Tcheck(...){return std::false_type{}; }

  static constexpr auto xv = Tcheck(static_cast<PotentialDerived*>(0));

template < class T1 > void  What()
{
        puts (__PRETTY_FUNCTION__);
}
  
  enum { value = sizeof(check(static_cast<PotentialDerived*>(0))) == sizeof(yes) };
};
 
template <class C, class P>
bool IsDerived() {
///	What<C>();
    return IsDerivedFrom<C, P>::xv;
    //return IsDerivedFrom<C, P>::value;
}

void testthis(B *in)
{
	std::cout << "Called this \n";
}

int main(int c , char * v[])
{
       auto x = IsDerived<B,D>();
       if ( x ) std::cout << "Yes\n";
       x = IsDerived<D,B>();
       if ( x ) std::cout << "Yes\n";
       D d;
       testthis(&d);
return c + (int) v[0][0] ;
}




