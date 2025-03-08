#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
    Planet earth;
    Planet moon;
    Background background;

    void Game::Init()
    {
        earth = Planet();
        earth.initialize();

        moon = Planet();
        moon.x = 420;
        moon.y = -50;
        moon.initialize();

        background = Background();
    }

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);

        // background
        background.update(screen, player);

        // player
        player->applyGravity(&earth);
		player->applyGravity(&moon);
        player->move();

        // ship
		ship->update(screen, player);

        // planet
		earth.update(screen, player);
		moon.update(screen, player);
    }
};