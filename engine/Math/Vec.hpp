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

  // Maybe these can be consteval in the future? unsure
	constexpr T* begin() const { return const_cast<T*>(data); };
	constexpr T* end() const { return begin() + count; };

	constexpr T operator[](int idx) const { return data[idx]; };
	constexpr T& operator[](int idx) { return data[idx]; };

  // Unary +/- (not much of a point in + but whatever)
  constexpr Vec<T, count> operator+() { return *this; }
  constexpr Vec<T, count> operator-() {
    Vec<T, count> ret = *this;

    for (T& el : ret) {
      el = -el;
    }

    return ret;
  }

  // Four functions for compound assignment operators +=, -=, *=, /=
  constexpr Vec<T, count>& operator+=(T addend) {
    for (T& el : *this) {
      el += addend;
    }

    return *this;
  }
  constexpr Vec<T, count>& operator-=(T scalar) {
    for (T& el : *this) {
      el -= scalar;
    }

    return *this;
  }
  constexpr Vec<T, count>& operator*=(T scalar) {
    for (T& el : *this) {
      el *= scalar;
    }

    return *this;
  }
  constexpr Vec<T, count>& operator/=(T divisor) {
    for (T& el : *this) {
      el /= divisor;
    }

    return *this;
  }

  // 3 functions for +, -, / (* will be outside class declaration)
  constexpr Vec<T, count> operator+(T addend) {
    Vec<T, count> ret = *this;
    return ret += addend;
  }
  constexpr Vec<T, count> operator-(T scalar) {
    Vec<T, count> ret = *this;
    return ret -= scalar;
  }
  constexpr Vec<T, count> operator/(T divisor) {
    Vec<T, count> ret = *this;
    return ret /= divisor;
  }
};

// v * scalar, scalar * v
template <typename T, size_t count>
constexpr Vec<T, count> operator*(const Vec<T, count>& v, T scalar) {
  Vec<T, count> ret = v;
  return ret *= scalar;
}
template <typename T, size_t count>
constexpr Vec<T, count> operator*(T scalar, const Vec<T, count>& v) {
  return v * scalar;
}

typedef Vec<> V3;
typedef Vec<i32> V3i;
typedef Vec<ui32> V3ui;
