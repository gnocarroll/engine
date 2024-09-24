#include "engine/Math/Vec.hpp"

template<typename T, size_t count>
std::istream& operator>>(std::istream& istr, Vec<T, count>& v) {
    for (T& el : v) {
        istr >> el;
    }

    return is;
}

template<typename T, size_t count>
std::ostream& operator<<(std::ostream& ostr, Vec<T, count>& v) {
    for (const T& el : v) {
        ostr << el;
    }

    return ostr;
}
