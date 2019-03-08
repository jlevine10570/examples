#include <memory>
#include <iostream>

void fun1(std::shared_ptr<int> sp)
{
    std::cout << " In fun1: sp.use_count() == " << sp.use_count() << '\n';
}
 std::shared_ptr<int>  fun2(std::shared_ptr<int> sp)
{
    std::cout << "In fun2: sp.use_count() == " << sp.use_count() << '\n';
   return  sp ;
}


int main()
{
    auto sp1 = std::make_shared<int>(5);
    std::cout << "Before any call sp1.use_count() == " << sp1.use_count() << '\n';

    fun1(sp1);
    std::cout << "after fun1 sp1.use_count() == " << sp1.use_count() << '\n';
    auto x = fun2(sp1);
     std::cout << "after fun2 sp1.use_count() == " << sp1.use_count() << '\n';

}

