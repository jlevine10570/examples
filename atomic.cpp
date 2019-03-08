#include <iostream>
#include <cstdlib>
#include <atomic>


std::atomic<char *> zz[10];
int main()
{
    std::cout << "Hello, Wandbox!" << std::endl;
    zz[2] = nullptr;
}


void read (){
    static int loc=0;
for (;;)
{
++loc;
if ( loc == 9 ) loc = 0;
   char * x  = zz[loc];
   if ( x == nullptr) 
   continue;
   zz[loc] = nullptr;
}
}




void write  (){
    static int loc=0;
for (;;)
{
++loc;
if ( loc == 9 ) loc = 0;
   char * x ;
    zz[loc].store(x); 
 
}
}
