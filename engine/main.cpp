#include <iostream>

#include "engine/Math/Vec.hpp"
#include "engine/Math/Mat.hpp"

int main() {
	M33 ident = M33::Identity();

	std::cout << ident << '\n';

	return 0;
}
