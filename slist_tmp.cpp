
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

template<class D> struct node
{
    D data;
    std::shared_ptr<node<D>> next{};
};

template <class D>class linked_list
{
private:
    std::shared_ptr <node<D>>  head{},tail{};
public:
    linked_list():head(nullptr),tail(nullptr)
    {
;
    }

    void add_node(D n)
    {
        std::shared_ptr<node<D>> tmp = std::make_shared<node<D>>();
        tmp->data = n;
        tmp->next = nullptr;

        if(head == nullptr)
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
void display()
{
display(this->head);
}
private:
void display(std::shared_ptr<node<D>> head)
    {
        if(head == nullptr)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
    }
};

int foo ( linked_list<int> &a )
{
    a.add_node(1);
    a.add_node(2);
    return 0;
}

int main()
{
    linked_list<int> a;
foo(a);
a.display();
}
 
