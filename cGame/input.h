#pragma once
#ifndef INPUT_H 
#define INPUT_H

#include <map>

#include <SDL2/SDL.h>

class Input
{
public:
	Input();
	~Input();

	void BeginNewFrame();
	void KeyUpEvent(const SDL_Event& event);
	void KeyDownEvent(const SDL_Event& event);

	bool WasKeyPressed(SDL_Scancode key);
	bool WasKeyReleased(SDL_Scancode key);
	bool IsKeyHeld(SDL_Scancode key);

private:
	std::map<SDL_Scancode, bool>	_heldKeys;
	std::map<SDL_Scancode, bool>	_pressedKeys;
	std::map<SDL_Scancode, bool>	_releasedKeys;
};

#endif

