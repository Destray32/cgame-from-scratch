#pragma once
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

/* AnimatedSprite class
* Holds logic for animated sprites
* 
*/

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(Graphics& graphics, const std::string& filePath,
		int sourceX, int sourceY, int height, int width, float posX, float posY, float timeToUpdate) {}

	/* void PlayAnimation
	* Plays specified animation if it's not playing 
	*/
	void playAnimation(std::string animation, bool once = false);

	/* void Update
	* Odswieza animowany sprite (timer)
	*/
	void Update(float elapsedTime);

	/* void Draw
	* Rysuje sprite na ekranie
	*/
	void Draw(Graphics& graphics, int x, int y);

	/* void SetupAnimation
	* Wymagana funkcja, która ustawia wszystkie animacje dla sprajtu
	*/
	virtual void SetupAnimation();

private:
	std::map<std::string, std::vector<SDL_Rect>> _animations;
};

#endif

