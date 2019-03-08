#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <string>
using namespace std;

// Create a simple large int class, that at this time only does addition, all
// methods are static
class largeInt {
private:
  // Function for finding sum of larger numbers
  // The longer of the two inputs is expected second
  static string findSumInternal(const string_view &str1,
                                const string_view &str2) {

    //
    // Take an empty string for storing result
    string str = "";

    // Calculate lenght of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initialy take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i = n1 - 1; i >= 0; i--) {
      // compute sum of
      // current digits and carry
      int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
      str.push_back(sum % 10 + '0');
      carry = sum / 10;
    }

    // Add remaining digits of str2[]
    for (int i = n2 - n1 - 1; i >= 0; i--) {
      int sum = ((str2[i] - '0') + carry);
      str.push_back(sum % 10 + '0');
      carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
      str.push_back(carry + '0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
  }

public:
  // Funtion to return true or false and the output is done via a parameter
  static bool addNum(const string &str1, const string &str2, std::string &out) 
  {
    auto ret = addNum(str1, str2);
    if (ret == "-1")
      return false;
    else {
      out = ret;
      return true;
    }
  }

  // This method performs all validation of the inputs and call the underlying
  // method A return of "-1" is an error case
  static std::string addNum(const string &str1, const string &str2) {

    const auto c1 = str1.find_first_not_of("0123456789");
    const auto c2 = str2.find_first_not_of("0123456789");

    // Validate input characters
    if ((c1 != std::string::npos) || (c2 != std::string::npos)) {
      std::cerr << "Error Input may only contain the digits 0-9, no other "
                   "characters permitted \n";
      return "-1";
    }

    // Check for leading zeros
    if ((str1.length() > 1 && str1[0] == '0') ||
        (str2.length() > 1 && str2[0] == '0')) {
      std::cerr << "Error Input may not contain leaing zeros\n";
      return "-1";
    }

    // An inexpensive way to get the data in form we need
    // With the longer string second
    if (str1.length() > str2.length())
      return findSumInternal(str2, str1);
    else
      return findSumInternal(str1, str2);
  }
};
int main(int c, char *v[]) {
  if (c != 3) {
    std::cerr << "Please enter two arguments. Each of the form 1-n base 10 "
                 "digits (i.e [0-9]), with no leading zeros \n";
    exit(1);
  }
  string out;
  auto ret = largeInt::addNum(v[1], v[2], out);
  if (ret)
    std::cout << out << '\n';
  return 0;
}
