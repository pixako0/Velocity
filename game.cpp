#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
    Background background;

    Planet sun;
    Planet mercury;
    Planet venus;
    Planet earth;
    Planet moon;

    void Game::Init()
    {
        sun = Planet();
        sun.asset = "assets/planets/sun.png";
        sun.planetSize = 515;
        sun.name = "Sun";
        sun.dieOnCollide = true;
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

        earth = Planet();
        earth.name = "Earth";
        earth.asset = "assets/planets/earth.png";
        earth.x = -6080;
        earth.y = -1800;
        earth.planetSize = 165;
        earth.initialize();

        moon = Planet();
        moon.name = "Moon";
        moon.asset = "assets/planets/moon.png";
        moon.x = -5780;
        moon.y = -2306;
        moon.planetSize = 65;
        moon.initialize();

        player->initialize();

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
        player->applyGravity(&earth);
        player->applyGravity(&moon);
        player->move();
        ship->update(screen, player);

        // planets
		sun.update(screen, player);
		mercury.update(screen, player);
        venus.update(screen, player);
        earth.update(screen, player);
        moon.update(screen, player);
    }
};