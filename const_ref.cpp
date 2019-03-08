#include <iostream>

template<typename T>
class Wrapper
{
public:
    Wrapper(T const& value) : value_(value) {}
    
    T const& get() const { return value_; }
    
private:
    T value_;
};
#if 0
template<typename T>
class WrapperAlt // will give error
{
public:
    Wrapper(T const& value) : value_(value) {}
    
    std::remove_reference_t<T> const& get() const { return value_; }
    
private:
    T value_;
};
#endif 
int main()
{
    using IntRefWrapperS = Wrapper<int>;
    using IntRefWrapper = Wrapper<int&>;

    int a = 42;
    IntRefWrapper intRefWrapper(a);
    
    int & x = intRefWrapper.get();
    intRefWrapper.get() = 43;

    std::cout << "a is now " << a << '\n';

    x = 44;

    std::cout << "a is now " << a << '\n';
}
