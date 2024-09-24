#pragma once

#include <cstddef>
#include <iostream>

#include "engine/MyIntDef.hpp"

template <typename T = float, size_t count = 3> struct Vec {
private:
  T data[count];

public:
  consteval Vec() : data() {}

  template <typename... Args>
  constexpr Vec(Args... _data) : data({_data...}) {}

  consteval size_t size() { return count; }

  constexpr T *begin() const { return const_cast<T *>(data); };
  constexpr T *end() const { return begin() + count; };

  constexpr T operator[](int idx) const { return data[idx]; };
  constexpr T &operator[](int idx) { return data[idx]; };

  // Unary +/- (not much of a point in + but whatever)
  constexpr Vec<T, count> operator+() { return *this; }
  constexpr Vec<T, count> operator-() {
    Vec<T, count> ret = *this;

    for (T &el : ret) {
      el = -el;
    }

    return ret;
  }

  // Operations with other vector
  // +=, -=
  constexpr Vec<T, count> &operator+=(const Vec<T, count> &addend) {
    for (size_t i = 0; i < count; i++) {
      data[i] += addend[i];
    }

    return *this;
  }
  constexpr Vec<T, count> &operator-=(const Vec<T, count> &other) {
    for (size_t i = 0; i < count; i++) {
      data[i] -= other[i];
    }

    return *this;
  }

  // +, -
  constexpr Vec<T, count> operator+(const Vec<T, count> &addend) const {
    Vec<T, count> ret = *this;
    return ret += addend;
  }
  constexpr Vec<T, count> operator-(const Vec<T, count> &other) const {
    Vec<T, count> ret = *this;
    return ret -= other;
  }

  // v * v (DOT PRODUCT)
  constexpr T operator*(const Vec<T, count> &other) const {
    T ret = data[0] * other[0];

    for (size_t i = 1; i < count; i++) {
      ret += data[i] * other[i];
    }

    return ret;
  }

  // Operations with scalar below
  // Four functions for compound assignment operators +=, -=, *=, /=
  constexpr Vec<T, count> &operator+=(T addend) {
    for (T &el : *this) {
      el += addend;
    }

    return *this;
  }
  constexpr Vec<T, count> &operator-=(T scalar) {
    for (T &el : *this) {
      el -= scalar;
    }

    return *this;
  }
  constexpr Vec<T, count> &operator*=(T scalar) {
    for (T &el : *this) {
      el *= scalar;
    }

    return *this;
  }
  constexpr Vec<T, count> &operator/=(T divisor) {
    for (T &el : *this) {
      el /= divisor;
    }

    return *this;
  }

  // 3 functions for +, -, / (* will be outside class declaration)
  constexpr Vec<T, count> operator+(T addend) const {
    Vec<T, count> ret = *this;
    return ret += addend;
  }
  constexpr Vec<T, count> operator-(T scalar) const {
    Vec<T, count> ret = *this;
    return ret -= scalar;
  }
  constexpr Vec<T, count> operator/(T divisor) const {
    Vec<T, count> ret = *this;
    return ret /= divisor;
  }
};

// v * scalar, scalar * v
template <typename T, size_t count>
constexpr Vec<T, count> operator*(const Vec<T, count> &v, T scalar) {
  Vec<T, count> ret = v;
  return ret *= scalar;
}
template <typename T, size_t count>
constexpr Vec<T, count> operator*(T scalar, const Vec<T, count> &v) {
  return v * scalar;
}

/*
 *  Cross product
 *  I am aware that analogous product exists for vectors of other dimensions
 *  but I will just define this for vectors of 3 dimensions.
 */
template <typename T>
constexpr Vec<T, 3> operator^(const Vec<T, 3> &v1, const Vec<T, 3> &v2) {
  return Vec<T, 3>(v1[1] * v2[2] - v1[2] * v2[1],
                   v1[2] * v2[0] - v1[0] * v2[2],
                   v1[0] * v2[1] - v1[1] * v2[0]);
}

// IO
template<typename T, size_t count>
std::istream& operator>>(std::istream& istr, Vec<T, count>& v);

template<typename T, size_t count>
std::ostream& operator<<(std::ostream& ostr, Vec<T, count>& v);

// typedefs for vectors that are likely to be used frequently
typedef Vec<> V3;
typedef Vec<i32> V3i;
typedef Vec<ui32> V3ui;
