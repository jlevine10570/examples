#include <iostream>

template <typename T>
struct HasSize // no using this just an example
{
  typedef char (&yes)[1];
  typedef char (&no)[2];

  template <typename C> static yes check(decltype(&C::size));
  template <typename> static no check(...);

  static bool const value =
      sizeof(check<T>(0)) == sizeof(yes); // Make a yes/no value , very screwy
};

template <typename Derived> class baseClass {
public:
  template <typename T> struct HasImplCode {

    template <typename C>
    static constexpr std::true_type isDmpl(decltype(&C::do_something_impl)) {
      return std::true_type{};
    }
    template <typename> static constexpr std::false_type isDImpl(...) {

      return std::false_type{};
    }



    static constexpr auto newcheck = isDmpl<T>(0);
  };

  template <class T, bool HasImpl> class Runner {
  public:
    void _run(T &obj) { obj.do_something_impl(); }
  };
  template <class T> class Runner<T, false> {
  public:
    void _run(T &obj) { this->do_something_impl(); }
  };

  void do_my_something(Derived &obj) {
    std::cout << " bool " << HasImplCode<Derived>::newcheck;
  }

  void do_something() {
    static_cast<Derived *>(this)->do_something_impl(); // !!!!!!!!!!!!
  }

private:
  // Derived *D;
  void do_something_impl() {
    std::cout << "The base class\n";
    // Default implementation
  }
};

class Foo : public baseClass<Foo>

{
public:
  void do_something_impl() { std::cout << "The dervied class\n"; }
};

class Bar : public baseClass<Bar> {};

template <typename Derived> void use(baseClass<Derived> &b) {
  b.do_something();
}

template <typename Derived> void useMe(Derived &b) {
  std::cout << "call \n";
  b.do_my_something(b);
}

main() {
  Foo foo{};
  // use (foo);
  useMe(foo);
  Bar bar{};

  // use (bar);
  useMe(bar);
  // std::cout << HasSort<int>::value <<std::endl;
  //	std::cout << HasSort<int>::stat <<std::endl;
  //	int vals[10];
  //	Runner<Foo> l;
  //	l.runIt(foo);
  // begin(vals);
}
