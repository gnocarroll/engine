#include <iostream>

#include "engine/Math/Vec.hpp"

int main() {
  V3 v1(0.5f, 0.5f, 0.0f);
  V3 v2(0.0f, 1.0f, 0.0f);

  std::cout << (v1 ^ v2) << '\n';

  return 0;
}
