#include "animatedsprite.h"
#include "graphics.h"
#include "sprite.h"
#include "globals.h"

#include <vector>


/* AnimatedSprite class
* Animuje sprite
*/

AnimatedSprite::AnimatedSprite() 
{

}

AnimatedSprite::AnimatedSprite(Graphics& graphics, const std::string& filePath,
	int sourceX, int sourceY, int height, int width, float posX, float posY, float timeToUpdate) :
	Sprite(graphics, filePath, sourceX, sourceY, height, width, posX, posY),
	_frameIndex(0),
	_timeToUpdate(timeToUpdate),
	_visible(true),
	_currentAnimationOnce(false),
	_currentAnimation(""),
	_timeElapsed(0)
{

}

void AnimatedSprite::AddAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset)
{
	std::vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++)
	{
		SDL_Rect newRect = { (i + x) * width, y, width, height };
		rectangles.push_back(newRect);
	}
	this->_animations.insert(std::pair<std::string, std::vector<SDL_Rect> >(name, rectangles));
	this->_offsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::ResetAnimation()
{
	this->_animations.clear();
	this->_offsets.clear();
}

void AnimatedSprite::PlayAnimation(std::string animation, bool once /* = false */)
{
	this->_currentAnimationOnce = once;
	if (this->_currentAnimation != animation)
	{
		this->_currentAnimation = animation;
		this->_frameIndex = 0;
	}
}

void AnimatedSprite::SetVisible(bool visible)
{
	this->_visible = visible;
}

void AnimatedSprite::StopAnimation()
{
	this->_frameIndex = 0;
	this->AnimationDone(_currentAnimation);
}

void AnimatedSprite::Update(float elapsedTime)
{
	Sprite::Update();

	this->_timeElapsed += elapsedTime;
	if (this->_timeElapsed > this->_timeToUpdate)
	{
		this->_timeElapsed -= this->_timeToUpdate;
		if (this->_frameIndex < this->_animations[this->_currentAnimation].size() - 1)
		{
			this->_frameIndex++;
		}
		else
		{

			if (this->_currentAnimationOnce == true)
			{
				this->SetVisible(false);
			}
			this->_frameIndex = 0;
			this->AnimationDone(_currentAnimation);
		}
	}
}

void AnimatedSprite::Draw(Graphics& graphics, int x, int y)
{
	if (this->_visible)
	{
		SDL_Rect destintationRect;
		destintationRect.x = x + this->_offsets[this->_currentAnimation].x;
		destintationRect.y = y + this->_offsets[this->_currentAnimation].y;
		destintationRect.w = this->_sourceRect.w * globals::SPRTE_SCALE;
		destintationRect.h = this->_sourceRect.h * globals::SPRTE_SCALE;

		SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];
		graphics.BlitSurface(this->_spriteSheet, &sourceRect, &destintationRect);
	}
}

void AnimatedSprite::AnimationDone(std::string currentAnimation)
{

}

void AnimatedSprite::SetupAnimation()
{
	this->AddAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
}


