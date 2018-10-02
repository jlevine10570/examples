#include <functional>
#include <iostream>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;
int main()
{
vector<int> ints{ 6, 3, 10, 5, 16, 8, 4, 2, 1 };
vector<string> strs{
"O'Neill", "Carter", "Jackson", "Teal'c" };
sort(ints.begin(), ints.end(), greater<>());
sort(strs.begin(), strs.end(), greater<>());
for (const auto& e : ints) { cout << e << endl; }
for (const auto& e : strs) { cout << e << endl; }
}
