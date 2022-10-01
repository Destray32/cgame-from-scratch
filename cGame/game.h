#pragma once
#ifndef GAME_H
#define GAME_H

#include "animatedsprite.h"
#include "Engine/types.h"
#include "player.h"

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

	Player _player;
};

#endif