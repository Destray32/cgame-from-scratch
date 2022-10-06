#include "player.h"
#include "animatedsprite.h"

Player::Player() : _dx(0.0), _dy(0.0) {}

Player::Player(Graphics& graphics, Vector2 spawnPoint) :
	// przypisanie kordynatow spawnpointu
	_dx(spawnPoint.x),
	_dy(spawnPoint.y),
	AnimatedSprite(graphics, "content/sprites/MyCharTransparent.png", 0, 0, 16, 16, _dx, _dy, 100)
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

void Player::Update(float elapsedTime)
{
	// aktualizacja pozycji na osi 'x'
	this->_x += this->_dx * elapsedTime;
}

