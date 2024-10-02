#pragma once

#include "Math/Vec.hpp"

template <typename T = float, size_t nRows = 3, size_t nCols = nRows>
struct Mat {
private:
	Vec<T, nCols> rows[nRows];

public:
	Mat() : rows{} {};

	template <typename... Args>
	constexpr Mat(Args... _rows) : rows{_rows...} {}

	constexpr Vec<T, nCols>* begin() const { return const_cast<Vec<T, nCols>*>(rows); }
	constexpr Vec<T, nCols>* end() const { return begin() + nRows; }

	constexpr Vec<T, nCols>& operator[](int idx) { return rows[idx]; }

	static constexpr Identity() {
		static_assert(nRows == nCols, "Identity only works for square Mat");

		Mat<T, nRows, nCols> ret;

		for (size_t i = 0; i < nRows; i++) {
			ret[i][i] = 1.0f;
		}

		return ret;
	}
};

// frequently used
typedef Mat<> M33;
typedef Mat<float, 4, 4> M44;