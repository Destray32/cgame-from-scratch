#include "sprite.h"
#include "graphics.h"
#include "globals.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY,
	int height, int width, float posX, float posY) : 
											_x(posX), _y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.LoadImage(filePath));

	if (this->_spriteSheet == NULL)
	{
		printf("\nError: Nie mozna zaladowac obrazu\n");
	}
}

Sprite::~Sprite()
{

}

void Sprite::Draw(Graphics& graphics, int x, int y)
{
	SDL_Rect destinatonRectangle = { x, y, this->_sourceRect.w * globals::SPRTE_SCALE, this->_sourceRect.h * globals::SPRTE_SCALE };
	graphics.BlitSurface(this->_spriteSheet, &this->_sourceRect, &destinatonRectangle);
}

void Sprite::Update()
{

}

