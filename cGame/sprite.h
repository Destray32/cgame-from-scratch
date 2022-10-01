#pragma once
#ifndef SPRITE_H
#define SPRITE_H

/* Sprite class
* Przechowuje informacje dla indywidualnych spritów
*/

#include <SDL2/SDL.h>

#include <string>

class Graphics;

class Sprite
{
public:
	Sprite();
	Sprite(Graphics& graphics, const std::string& filePath,
		int sourceX, int sourceY, int height, int width, float posX, float posY);

	virtual ~Sprite();
	void Update();
	void Draw(Graphics& graphics, int x, int y);

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

private:
	float _x, _y;
};

#endif
