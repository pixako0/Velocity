#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	static Sprite ship(new Surface("assets/Foozle_2DS0011_Void_MainShip/Main Ship/Main Ship - Bases/PNGs/Main Ship - Base - Full health.png"), 1);

	void Game::Tick(float deltaTime)
	{
		screen->Clear(0);
		player->move();
		ship.Draw(screen, player->x, player->y);
	}
};