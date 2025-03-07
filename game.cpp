#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	static Sprite ship(new Surface("assets/Foozle_2DS0011_Void_MainShip/Main Ship/Main Ship - Bases/PNGs/Main Ship - Base - Full health.png"), 1);
	static Sprite planetSprite(new Surface("assets/planets/planet.png"), 100);

	int totalDistance = 0;
	int xOffset = 0;
	int yOffset = 0;

	void Game::Init()
	{
		xOffset = screen->GetWidth() / 2;
		yOffset = screen->GetHeight() / 2;
	}

	int xDistance = 0;
	int xDistanceC = 0;
	int yDistance = 0;
	int yDistanceC = 0;

	void Game::Tick(float deltaTime)
	{
		screen->Clear(0);

		// player
		player->applyGravity(planet->planetsize, planet->gravityRange, planet->x, planet->y);
		player->move();
		ship.Draw(screen, xOffset - ship.GetWidthOffset(), yOffset - ship.GetHeightOffset());

		// planet
		planetSprite.SetFrame(planet->frameCount);
		planetSprite.Draw(screen, planet->x - player->x + xOffset - planetSprite.GetWidthOffset(), planet->y - player->y + yOffset - planetSprite.GetHeightOffset());
		planet->nextFrame();
	}
};