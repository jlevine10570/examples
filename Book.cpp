
#include <vector>
#include <iostream>

struct Pos
{
	Pos():price(0),size(0){};
	int price;
	int size;
	// pointer to AllOrders map 
	
};

struct Order
{
	Pos p;
	int id;
};

class AllOrder{
	//  unordered_map[price,std::forward_list<orders>>]
	//  POINTER to each order store also by id , can be invalidated and eventaully cleared 
	// map of id's to a table
	// each table entry has price size
};	
class Orders 
{
	private:
	std::vector<Order> vec;
	void add(const Order& p  ) // 
	{
	vec.push_back(p); 
	}
	};

class Book 
{
	private:
	std::vector<Pos> vec; // Use a douly linked list
	// heap for the rest 
	int front,back;
        public:
	Book():front(0),back(0)
	{
	vec.resize(100);
	};
	void add(const  Pos & p)
	{
		//find from front to back insert or update 
		//if out side of range add to heap
	}
	void remove(const  Pos & p)
	{
		//find from front to back and update  or remove and colapse
		//if out side of range remove heap
	}
	int getBest()
	{
		return vec[front].price;
	}

	
};

class Buy : public Book
{

};

int main( int x ,char *v[])
{
	Book buy;
}

