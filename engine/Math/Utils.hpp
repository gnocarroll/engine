#pragma once

namespace Math {

constexpr double pi = 3.14159265358979;
constexpr float piF = static_cast<float>(pi);

constexpr float radDegRatio = static_cast<float>(pi / 180.0);

constexpr float degToRad(float deg) { return deg * radDegRatio; }

constexpr float radToDeg(float rad) { return rad / radDegRatio; }

} // namespace Math
