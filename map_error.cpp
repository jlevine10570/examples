
#include <iostream>
#include <map>
#include <array>
#include <string>
#include <iterator>
#include <iostream>

class Data
{
private:
  static int _internalId;
  int _id;
    std::string _altName;
public:
    Data ()
  {
    _internalId++;
    _id = -1;
    _altName = "NO_Alternate_Name";
  }
  Data (int i, std::string in):Data ()
  {
    _id = i;
    _altName = in;
  }
  void getInfo ()
  {
    std::cout << "Alt name = " << _altName << " Id=" << _id <<
      " Total count =  " << _internalId << '\n';
  }

};

int
  Data::_internalId = 0;

int
main (int c , char *v[])
{
  std::map < std::string, Data > mapOfData;
  std::map < std::string, int > mapOfOffsets;
  mapOfData.emplace ("Jeremy", Data (1, std::string ("jer")));
  mapOfData.emplace ("Jacob", Data (2, std::string ("jake")));
  mapOfData.emplace ("Sydney", Data (3, std::string ("syd")));

  try				// Block 1 
  {
    mapOfData["Jeremy"].getInfo ();
    mapOfData["Jacob"].getInfo ();
    mapOfData["Sydney"].getInfo ();
  }
  catch (...)
  {
    std::cerr << "An exception block 1\n";
    exit (1);
  }

  try				// Block 2 
  {
    mapOfData["Jacob"].getInfo ();
    mapOfData["jacob"].getInfo ();
  }
  catch (...)
  {
    std::cerr << "An exception in block 2  \n";
    exit (1);
  }

}
