#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals {
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 1024;

	const float SPRTE_SCALE = 3.0f;
}

struct Vector2
{
	int	x, y;
	float fx, fy;

	Vector2() :
		x(0), y(0) {}

	Vector2(int x, int y) :
		x(x), y(y) {}

	Vector2(float x, float y) :
		fx(x), fy(y) {}

	Vector2 zero()
	{
		return Vector2(0, 0);
	}
};


#endif