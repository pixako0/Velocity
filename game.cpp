#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
    Planet earth;
    Planet moon;

    void Game::Init()
    {
        earth = Planet();
        moon = Planet();
        moon.x = 220;
        moon.y = -50;

        earth.initialize();
        moon.initialize();
    }

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);

        // player
        player->applyGravity(&earth);
		//player->applyGravity(&moon);
        player->move();

        // ship
		ship->update(screen, player);

        // planet
		earth.update(screen, player);
		moon.update(screen, player);
    }
};