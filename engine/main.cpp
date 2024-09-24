#include <iostream>

#include "engine/Math/Vec.hpp"


int main() {
	V3 v1;
  V3 v2;

  for (auto& el : v1) {
    std::cin >> el;
  }
  for (auto& el : v2) {
    std::cin >> el;
  }

  std::cout << v1 * v2 << '\n';

  return 0;
}
