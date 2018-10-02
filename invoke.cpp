#include <functional>
#include <iostream>
#include <iostream>
#include <memory>
#include <vector>

template <typename Range, typename Callable>
void transform_print(const Range &r, Callable c) {
  for (const auto &e : r) {
    std::cout << invoke(c, e) << std::endl;
  }
}

int main()
{

std::vector<std::pair<int, int>> v{{4, 40}, {5, 50}, {6, 60}};

 transform_print(v, [](const auto& p) { return p.first * p.first; });
 transform_print(v, &std::pair<int, int>::second);
}
