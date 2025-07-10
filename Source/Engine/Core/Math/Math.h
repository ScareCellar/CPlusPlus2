#pragma once
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>

namespace blood {
	namespace math {
		constexpr float pi = 3.1415926535897932384626433832795f;
		constexpr float twoPi = pi * 2;
		constexpr float halfPi = pi / 2;

		constexpr float radToDeg(float rad) { return rad * (180 / pi); }
		constexpr float degToRad(float deg) { return deg * (pi / 180); }
		
		inline float square(float num) { return num * num; }

		using std::min
			, std::clamp
			, std::sqrt
			, std::sqrtf
			, std::sin
			, std::sinf
			, std::cos
			, std::cosf;
	}
}