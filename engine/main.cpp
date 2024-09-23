#include <iostream>

#include "engine/Math/Vec.hpp"


int main() {
	V3 v(0.0f, 1.0f, 2.0f);
	
  v *= 2;

  for (const auto& el : v) {
    std::cout << el << '\n';
  }

  return 0;
}
