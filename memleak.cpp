#include <memory>
void noMemLeak( )
{
  auto data = std::make_unique<int>(1);
  *data = 15;
}
void memLeak( )
{
  int *data = new int;
  *data = 15;
}

int main( int c , char * v[] )
{
//memLeak();
noMemLeak();
}
