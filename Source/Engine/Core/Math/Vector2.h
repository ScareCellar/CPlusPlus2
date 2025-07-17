#pragma once
#include <cassert>
#include "Math.h"
namespace blood {
	template<typename T>
	struct Vector2 {
		union {
			struct { T x, y; };
			struct { T u, v; };
		};

		Vector2() = default;

		Vector2(T x, T y) : x{ x }, y{ y } {}

		T operator [] (unsigned int index) const { /*assert(i < index); */ return (&x)[index]; }

		Vector2 operator +(const Vector2& v) const { return Vector2{ x + v.x, y + v.y }; }
		Vector2 operator -(const Vector2& v) const { return Vector2{ x - v.x, y - v.y }; }
		Vector2 operator *(const Vector2& v) const { return Vector2{ x * v.x, y * v.y }; }
		Vector2 operator /(const Vector2& v) const { return Vector2{ x / v.x, y / v.y }; }

		Vector2& operator +=(const Vector2& v) { x += v.x, y += v.y; return this; };
		Vector2& operator -=(const Vector2& v) { x -= v.x, y -= v.y; return this; };
		Vector2& operator *=(const Vector2& v) { x *= v.x, y *= v.y; return this; };
		Vector2& operator /=(const Vector2& v) { x /= v.x, y /= v.y; return this; };

		

		//pythagorean theorum
		float LengthSqr() const { 
			return ((x * x) + (y * y));
		}
		float Length() const { return math::sqrtf(LengthSqr()); }
	};

	using ivec2 = Vector2<int>;
	using vec2 = Vector2<float>;
}