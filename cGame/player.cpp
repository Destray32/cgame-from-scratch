#include "player.h"
#include "animatedsprite.h"

Player::Player() : _x(0.0), _y(0.0) {}

Player::Player(Graphics& graphics, Vector2 spawnPoint) :
	_x(spawnPoint.x),
	_y(spawnPoint.y),
	AnimatedSprite(graphics, "content/sprites/MyCharTransparent.png", 0, 0, 16, 16, _x, _y, 100)
{
	this->SetupAnimation();
}

void Player::SetupAnimation()
{
	this->AddAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
}

void Player::AnimationDone(std::string currentAnimation)
{

}

