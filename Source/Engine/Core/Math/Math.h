#pragma once
#include <algorithm>

namespace blood {
	namespace math {
		constexpr float pi = 3.1415926535897932384626433832795f;
		constexpr float twoPi = pi * 2;
		constexpr float halfPi = pi / 2;

		constexpr float radToDeg(float rad) { return rad * (180 / pi); }
		constexpr float degToRad(float deg) { return deg * (pi / 180); }

		using std::min;
		using std::clamp;
	}
}