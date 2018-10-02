// https://anteru.net/blog/2009/03/14/385/
#include <iostream>
#include <memory>
#include <vector>
#include <iostream>
class Container
{
public:
    Container (const size_t size);

    Container (const Container& other);
    Container& operator =(const Container& other);

    int& operator [] (const int index);
    const int& operator [] (const int index) const;

private:
    class Impl;
    std::shared_ptr<Impl> impl_;
};

////////////////////////////////////////////////////////////////
// Implementation
#include <vector>

class Container::Impl
{
public:
    Impl (const size_t size)
    {
        vec.resize (size);
    }

    std::vector<int> vec;
};

Container::Container (const size_t size)
: impl_ (new Impl (size))
{
}

/*
We need those copy constructors, otherwise, we would
share our state. For most classes, it is best to make them
noncopyable anyway.
*/
Container::Container (const Container& other)
: impl_ (new Impl (other.impl_->vec.size ()))
{
    impl_->vec = other.impl_->vec;
}

Container& Container::operator = (const Container& other)
{
    impl_->vec = other.impl_->vec;

    return *this;
}

int& Container::operator [] (const int index)
{
    return impl_->vec [index];
}

const int& Container::operator [] (const int index) const
{
    return impl_->vec [index];
}

//////////////////////////
int main ()
{
    Container c (23);
    c[13] = 37;

    std::cout << c[13] << std::endl;

    Container copy = c;
    copy[13] = 4711;

    std::cout << c[13] << std::endl;
}

