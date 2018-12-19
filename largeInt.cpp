#include <bits/stdc++.h>
using namespace std;

// Function for finding sum of larger numbers
// Use string_view as we need only a "view" into the data.
// Use a ref (&)  as small string optimization will proably be of no use in the case
string findSumInternal(const string_view &input1, const string_view &input2) {

  // This is the internal call and we assume input 2 is longer then input 1
  
  // Take an empty string for storing result
  string str = "";

  // We need the length and releative size diff for both inputs
  int n1 = input1.length();
  int  n2 = input2.length();
  int diff = n2 - n1;

  // Initialy take carry zero
  int carry = 0;

  // Walk all the digits in the 
  for (int i = n1 - 1; i >= 0; i--) 
  {
	  // use " -'0' " to cahnge the char to a int value 
    int sum = ((input1[i] - '0') + (input2[i + diff] - '0') + carry);

    // Save the the digit 
    str.push_back(sum % 10 + '0');

    // Check for a calue to carry
    carry = sum / 10;
  }

  // Add remaining digits of input2[] as it is (maybe) longer then input1 
  for (int i = n2 - n1 - 1; i >= 0; i--) {
    int sum = ((input2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }

  // Add remaining carry
  if (carry)
    str.push_back(carry + '0');

  // The reuslut was built backwards so reverse it before returning
  reverse(str.begin(), str.end());

  return str;
}

// Driver code
string addNum(const string &input1, const string &input2) {
  if (input1.length() > input2.length())
    return findSumInternal(input2, input1);
  else
    return findSumInternal(input1, input2);
}
int main() {
  string input2 = "12";
  string input1 = "198111";
  cout << addNum(input1, input2) << '\n';
  cout << addNum(input2, input1) << '\n';
  return 0;
}
