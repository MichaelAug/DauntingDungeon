#pragma once

class Vector2 {
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	void normalise(); // DOES NOT WORK PROPERLY

	friend Vector2 operator-(const Vector2&,const Vector2&);
};