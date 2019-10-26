#pragma once
#include <assert.h>
#include <math.h>
class Vector2
{
public:
	Vector2()
		:x(0.0),y(0.0)
	{
	}
	Vector2(float x, float y)
		:x(x), y(y)
	{
	}

	bool operator== (const Vector2& rhs) const
	{
		return (x == rhs.x && y == rhs.y);
	}

	bool operator!= (const Vector2& rhs) const
	{
		return (x != rhs.x || y != rhs.y);
	}

	Vector2 operator+ (const Vector2& rhs) const
	{
		return Vector2(x + rhs.x, y + rhs.y);
	}

	Vector2 operator- (const Vector2& rhs) const
	{
		return Vector2(x - rhs.x, y - rhs.y);
	}

	Vector2 operator* (const float rhs) const
	{
		return Vector2(x * rhs, y * rhs);
	}

	Vector2 operator/ (const float rhs) const
	{
		assert(rhs != 0.0);
		// �˷�����ȳ��������
		float inv = 1.0f / rhs;
		return Vector2(x * inv, y * inv);
	}

	Vector2 operator- () const
	{
		return Vector2(-x, -y);
	}

	float length() const
	{
		return sqrt(x * x + y * y);
	}

	float squaredLength() const
	{
		return x * x + y * y;
	}

	float distance(const Vector2& rhs) const
	{
		return (*this - rhs).length();
	}

	float dot(const Vector2& vec) const
	{
		return x * vec.x + y * vec.y;
	}

	float cross(const Vector2& other) const
	{
		return x * other.y - y * other.x;
	}

public:
	float x, y;
};