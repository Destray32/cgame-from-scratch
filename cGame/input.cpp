#include "input.h"


Input::Input()
{

}

Input::~Input()
{
	
}


// Funkcja wywolywana na poczatku kazdej klatki
// resetuje klawisze
void Input::BeginNewFrame()
{
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

// Funkcja jest wywolywana przy kazdym kliknieciu przycisku
void Input::KeyDownEvent(const SDL_Event& event)
{
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;

}

// Funkcja jest wywolywana gdy przycisk zostanie puszczony
void Input::KeyUpEvent(const SDL_Event& event)
{
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

// Sprawdza czy w akutalnej klatce podany klawisz byl wcisniety
bool Input::WasKeyPressed(SDL_Scancode key)
{
	return this->_pressedKeys[key];
}

// Sprawdza czy w akutalnej klatce podany klawisz zosta³ puszczony
bool Input::WasKeyReleased(SDL_Scancode key)
{
	return this->_releasedKeys[key];
}

// Sprawdza czy w akutalnej klatce wciœniêty jest przycisk
bool Input::IsKeyHeld(SDL_Scancode key)
{
	return this->_heldKeys[key];
}
