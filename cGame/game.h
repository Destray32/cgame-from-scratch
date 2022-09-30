#pragma once
#ifndef GAME_H
#define GAME_H

#include "sprite.h"
#include "Engine/types.h"

class Graphics;
typedef uint32_t u32;

class Game {
public:
	Game();
	~Game();

private:
	void GameLoop();
	void Draw(Graphics& graphics);
	void Update(float elapsedTime);
	types::u32 time_left();

	Sprite _player;
};

#endif