#include "Vec.hpp"

template <typename T, size_t count>
consteval T* Vec<T, count>::begin() const {
	return &data;
}

template <typename T, size_t count>
consteval T* Vec<T, count>::end() const {
	return &data + count;
}

template <typename T, size_t count>
constexpr T Vec<T, count>::operator[](int idx) const {
	return data[idx];
}

template <typename T, size_t count>
constexpr T& Vec<T, count>::operator[](int idx) {
	return data[idx];
}