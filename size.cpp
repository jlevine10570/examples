#include<iostream> 
using namespace std; 
  
class base { 
    int arr[10];      
	public:
}; 

class basev { 
    int arr[10];      
	public:
    virtual int f() { return 10; }
}; 
  
class b1: public base { }; 
  
class b2: public base { }; 
  
class derived: public b1, public b2 {}; 
  
int main(void) 
{  
  cout<< "Sizeof of simple base class " <<sizeof(base)<<"\n"; 
  cout<< "Sizeof of simple base class , with virtual function " <<sizeof(vbase)<<"\n"; 
  cout<< "Sizeof of simple derived class " <<sizeof(derived)<<"\n"; 
  getchar(); 
  return 0; 
} 
