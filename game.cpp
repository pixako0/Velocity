#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
    Planet sun;
    Planet mercury;
    Planet venus;
    Background background;

    void Game::Init()
    {
        sun = Planet();
        sun.asset = "assets/planets/sun.png";
        sun.planetSize = 515;
        sun.name = "Sun";
        sun.initialize();

        mercury = Planet();
        mercury.name = "Mercury";
        mercury.x = 2220;
        mercury.y = -550;
        mercury.planetSize = 115;
        //mercury.asset = "assets/planets/mercury.png";
        mercury.initialize();

        venus = Planet();
        venus.name = "Venus";
        venus.asset = "assets/planets/venus.png";
        venus.x = 4420;
        venus.y = 2000;
        venus.planetSize = 165;
        venus.initialize();

        player->x = 4420;
        player->y = 2200;

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
        player->applyGravity(&venus);
        player->move();
        ship->update(screen, player);

        // planets
		sun.update(screen, player);
		mercury.update(screen, player);
        venus.update(screen, player);
    }
};