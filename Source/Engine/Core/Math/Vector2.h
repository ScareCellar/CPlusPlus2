#pragma once

template<typename T>
struct Vector2 {
	T x, y;

	Vector2() = default;

	Vector2(T x, T y) : x{ x }, y{ y } {}

	Vector2 Add(const Vector2& v);
};

using ivec2 = Vector2<int>;
using vec2 = Vector2<float>;