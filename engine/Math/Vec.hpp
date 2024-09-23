#pragma once

#include <cstddef>

#include "engine/MyIntDef.hpp"

template <typename T = float, size_t count = 3>
struct Vec {
private:
	T data[count];

public:
	consteval Vec() : data() {}

  template <typename... Args>
	constexpr Vec(Args... _data) : data({_data...}) {}

	consteval T* begin() const { return const_cast<T*>(data); };
	consteval T* end() const { return begin() + count; };

	constexpr T operator[](int idx) const { return data[idx]; };
	constexpr T& operator[](int idx) { return data[idx]; };
};

typedef Vec<> V3;
typedef Vec<i32> V3i;
typedef Vec<ui32> V3ui;
