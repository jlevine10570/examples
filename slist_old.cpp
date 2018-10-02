#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
void walk()
{
std::cout << "start \n";
 if ( head==NULL) std::cout << "empty list \n";
node *x=head;
int i=0;
for(;;)
{
std::cout  << "Position " << ++i << " is " << x->data; 
std::cout  << "\n";
x = x->next;
if ( x== NULL) break;
}
}


    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
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
for ( int z =0 ; z<1000 ; z++)
    a.add_node(10+z);
    return 0;
}

int main()
{
    linked_list a;
foo(a);
a.walk();
}
 
