
/* Graphics
* Wszystko co zwiazane z grafika w grze
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "graphics.h"
#include "globals.h"
#include "desktop.h"


Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(
		globals::SCREEN_WIDTH,
		globals::SCREEN_HEIGHT,
		0,
		&this->_window,
		&this->_renderer
	);

	SDL_SetWindowTitle(this->_window, "Gra");

	// zmiana koloru t�a okna gry
	SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);

	// Clear the entire screen to our selected color.
	SDL_RenderClear(this->_renderer);
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
	std::cout << "Destruktor klasy 'Graphics' uzyty\n";
}

SDL_Surface* Graphics::LoadImage(const std::string& filePath)
{
	if (this->_spriteSheets.count(filePath) == 0)
	{
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath];
}

void Graphics::BlitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::Flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Graphics::Clear() 
{
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->_renderer;
}