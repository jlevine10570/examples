#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

struct node
{
    int data;
    std::shared_ptr<node> next{};
};

class linked_list
{
private:
    std::shared_ptr <node>  head{},tail{};
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        std::shared_ptr<node> tmp = std::make_shared<node>();
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
};

int foo ( linked_list &a )
{
    a.add_node(1);
    a.add_node(2);
    return 0;
}

int main()
{
    linked_list a;
foo(a);
}
 
