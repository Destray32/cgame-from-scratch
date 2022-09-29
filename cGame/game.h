#pragma once
#ifndef GAME_H
#define GAME_H

#include "sprite.h"

class Graphics;

class Game {
public:
	Game();
	~Game();

private:
	void GameLoop();
	void Draw(Graphics& graphics);
	void Update(float elapsedTime);

	Sprite _player;
};

#endif