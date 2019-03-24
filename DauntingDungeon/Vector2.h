#pragma once
#include <iostream>

class Vector2 {
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	void normalise();

	float magnitude();

	void Normalise();

	float DotProduct(Vector2 a) const;

	void ToZero();

	friend Vector2 operator-(const Vector2&,const Vector2&);

	friend std::ostream& operator<<(std::ostream& o, const Vector2& v);
	//Vector2  operator-(const Vector2  &v) const;
	Vector2  operator+(const Vector2  &v) const;
	Vector2  operator/(const Vector2  &v) const;
	Vector2  operator*(float f) const;
	Vector2  operator/(float f) const;
	void operator+=(const Vector2  &v);
	void operator*=(float f);
	void operator-=(const Vector2  &a);
};