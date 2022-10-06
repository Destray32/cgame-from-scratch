#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"


class Player : public AnimatedSprite
{
public:

	Player();
	Player(Graphics& graphics, Vector2 spawnPoint);

	/* void MoveRight
	* Funkcja odpowiadajaca za operacje zwiazane z ruchem w prawo
	*/
	void MoveRight();

	/* void MoveLeft
	* Funkcja odpowiadajaca za operacje zwiazane z ruchem w lewo
	*/
	void MoveLeft();


	void SetupAnimation() override;
	void Update(float elapsedTime);

private:
	float _dx, _dy;
	int _health;

	void AnimationDone(std::string currentAnimation) override;
};
#endif // !PLAYER_H

