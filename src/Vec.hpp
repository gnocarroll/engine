#pragma once

#include <cstddef>

#include "MyIntDef.hpp"

template <typename T = float, size_t count = 3>
struct Vec {
private:
	T data[count];

public:
	consteval Vec() : data() {}
	constexpr Vec(T _data...) : data(_data) {}

	consteval T* begin() const;
	consteval T* end() const;

	constexpr T operator[](int idx) const;
	constexpr T& operator[](int idx);
};

typedef Vec<> V3;
typedef Vec<i32> V3i;
typedef Vec<ui32> V3ui;