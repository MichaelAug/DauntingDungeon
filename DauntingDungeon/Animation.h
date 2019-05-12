#pragma once

struct Animation {
	Vector2 startPos;
	int frames;
	int speed;

	Animation() {}
	Animation(Vector2 i, int f, int s) {
		startPos = i;
		frames = f;
		speed = s;
	}
};