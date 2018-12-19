#include "specialization.hpp"


int main() {
    A<char,0> a0;
    A<char,2> a2;
    A<char,3> a3;
    a0.f(); // OK, uses primary template’s member definition
    a2.g(); // OK, uses partial specialization's member definition
    a2.h(); // OK, uses fully-specialized definition of
            // the member of a partial specialization
    //a2.f(); // error: no definition of f() in the partial
            // specialization A<T,2> (the primary template is not used)
    a0.f(); // OK, uses primary template’s member definition
    a3.f();
}
