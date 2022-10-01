#pragma once
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

/* AnimatedSprite class
* Holds logic for animated sprites
*/

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(Graphics& graphics, const std::string& filePath,
		int sourceX, int sourceY, int height, int width, float posX, float posY, float timeToUpdate);

	/* void PlayAnimation
	* Plays specified animation if it's not playing
	*/
	void PlayAnimation(std::string animation, bool once = false);

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

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/* void AddAnimation
	* Dodaje animacje do mapy animacji dla spirte
	*/
	void AddAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/*void ResetAnimation
	* Resetuje wszystkie animacje zwi¹zane ze spritem
	*/
	void ResetAnimation();

	/* void StopAnimation
	* Zatrzymuje aktualn¹ animacje
	*/
	void StopAnimation();

	/* void SetVisible
	* Zmienia widocznosc animacji spirte
	*/
	void SetVisible(bool visible);

	/* void AnimationDone
	* Zawiera kod, który zostaje wykonany gdy animacja sie konczy
	*/
	virtual void AnimationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect>> _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

#endif

