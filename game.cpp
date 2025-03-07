#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
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

        // ship
		ship->update(screen, player);

        // planet
        planetSprite.SetFrame(planet->frameCount);
        planetSprite.Draw(screen, planet->x - player->x + xOffset - planetSprite.GetWidthOffset(), planet->y - player->y + yOffset - planetSprite.GetHeightOffset());
        planet->nextFrame();
    }
};