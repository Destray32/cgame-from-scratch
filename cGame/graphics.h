#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H


/*	Graphics
*	Wszystko co zwiazane z grafika w grze
*/

#include <SDL2/SDL.h>

#include <map>
#include <string>

struct	SDL_Window;
struct	SDL_Renderer;

class Graphics
{
public:
	Graphics();
	~Graphics();


	/*	SDL_Surface* LoadImage
	*	£aduje obraz to mapy _spriteSheets jeœli takowa nie istnieje
	*	W rezultacie, ka¿dy obraz bêdzie ³adowany tylko raz
	*	Zwraca zdjecie z mapy 
	*/
	SDL_Surface* LoadImage(const std::string& filepath);

	/* void BlitSurface
	* Wstawia (rysuje) teksture na wybrane miejsce na ekranie
	*	
	*/
	void BlitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* void Flip
	*	Renderuje wszystko w oknie
	*/
	void Flip();

	/* void Clear
	*	Czyœci okno
	*/
	void Clear();

	/* SDL_Renderer getRenderer
	*	Zwracanie renderera
	*/
	SDL_Renderer* getRenderer() const;

	void ChangeBackgroundColor(int r, int g, int b, int a);

private:
	SDL_Window*		_window;
	SDL_Renderer*	_renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};
#endif

