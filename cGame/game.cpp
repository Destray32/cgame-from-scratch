#include "game.h"
#include "graphics.h"
#include "input.h"
#include "desktop.h"
#include "Engine/types.h"
#include "animatedsprite.h"
#include "player.h"

#include <SDL2/SDL.h>

/* Game class
* Glowna klasa gry. Zaimplementowana jest tutaj miedzy innymi
* pêtla gry.
*/

void PlayerControl(Input& input);

namespace {
	const int	FPS = 50;
	const int	MAX_FRAME_TIME = 5 * 1000 / FPS;

	// zmienne potrzebne do implementacji mojego capa fpsów.
	const int	TICK_INTERVAL = 15;
	static types::u32 next_time;


}

namespace cords {
	// kordynaty sprite gracza (testowe)
	float	playerPosX = 0.0f;
	float	playerPosY = 0.0f;

}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->GameLoop();
}

Game::~Game()
{
	SDL_Quit();
}

void Game::GameLoop()
{
	Graphics	graphics;
	Input		input;
	SDL_Event	event;


	this->_player = Player(graphics, Vector2(100, 100));

	this->_player.PlayAnimation("RunLeft");

	int LAST_UPDATE_TIME = SDL_GetTicks();

	// GAME LOOP
	while (1)
	{
		input.BeginNewFrame();

		next_time = SDL_GetTicks() + TICK_INTERVAL;

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0)
				{
					input.KeyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				input.KeyUpEvent(event);
			}
			if (event.type == SDL_QUIT)
			{
				return;
			}
			if (input.WasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
			{
				return;
			}
		}


		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->Update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		// Chwilowy sposob na ograniczenie wykonywanych kaltek.
		SDL_Delay(time_left());
		next_time += TICK_INTERVAL;

		this->Draw(graphics);
	}
}

void Game::Draw(Graphics& graphics)
{
	graphics.Clear();

	this->_player.Draw(graphics, 0, 0);

	graphics.Flip();
}

void Game::Update(float elapsedTime)
{
	this->_player.Update(elapsedTime);
}

types::u32 Game::time_left()
{
	types::u32 now;

	now = SDL_GetTicks();
	if (next_time <= now)
	{
		return 0;
	}
	else
	{
		return next_time - now;
	}
}




/* Inne funkcje (nie implementacje klasy Game)
*
*/

/* void PlayerControl
* Zarz¹dzanie pozycj¹ sprite gracza. Nie powinno to sie tutaj znajdowac.
* Umiescilbym to w oddzielnej klasie gracza.
*/
void PlayerControl(Input& input)
{

#pragma region Key Handling

	if (input.WasKeyPressed(SDL_SCANCODE_A) || input.IsKeyHeld(SDL_SCANCODE_A))
	{
		cords::playerPosX -= 5.5f;
	}
	if (input.WasKeyPressed(SDL_SCANCODE_D) || input.IsKeyHeld(SDL_SCANCODE_D))
	{
		cords::playerPosX += 5.5f;
	}
	if (input.WasKeyPressed(SDL_SCANCODE_W) || input.IsKeyHeld(SDL_SCANCODE_W))
	{
		cords::playerPosY -= 5.5f;
	}
	if (input.WasKeyPressed(SDL_SCANCODE_S) || input.IsKeyHeld(SDL_SCANCODE_S))
	{
		cords::playerPosY += 5.5f;
	}

#pragma endregion Key Handling
}