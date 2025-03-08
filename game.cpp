#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
    Planet sun;
    Planet mercury;
    Background background;

    void Game::Init()
    {
        sun = Planet();
        sun.asset = "assets/planets/sun.png";
        sun.planetSize = 515;
        sun.initialize();

        mercury = Planet();
        mercury.x = 1220;
        mercury.y = -50;
        mercury.planetSize = 115;
        //mercury.asset = "assets/planets/mercury.png";
        mercury.initialize();

        background = Background();
    }

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);

        // background
        background.update(screen, player);

        // player
        player->applyGravity(&sun);
        player->applyGravity(&mercury);
        player->move();

        // ship
		ship->update(screen, player);

        // planet
		sun.update(screen, player);
		mercury.update(screen, player);
    }
};