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
        planets.push_front(sun);

        mercury = Planet();
        mercury.name = "Mercury";
        mercury.x = 2220;
        mercury.y = -550;
        mercury.planetSize = 115;
        //mercury.asset = "assets/planets/mercury.png";
        mercury.initialize();
        planets.push_front(sun);

        venus = Planet();
        venus.name = "Venus";
        venus.asset = "assets/planets/venus.png";
        venus.x = 4420;
        venus.y = 2000;
        venus.planetSize = 165;
        venus.initialize();
        planets.push_front(venus);

        earth = Planet();
        earth.name = "Earth";
        earth.asset = "assets/planets/earth.png";
        earth.x = -6080;
        earth.y = -1800;
        //earth.velocityY = 50;
        earth.planetSize = 165;
        earth.initialize();
        planets.push_front(earth);

        moon = Planet();
        moon.name = "Moon";
        moon.asset = "assets/planets/moon.png";
        moon.x = -6080;
        moon.y = -1200;
        moon.planetSize = 65;
        moon.velocityX = -20;
        moon.initialize();
        planets.push_front(moon);

        player->initialize();
        test->initialize();

        background = Background();
    }

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);

        // background
        background.update(screen, player);

        // player
        player->update(screen);
        test->update(screen);
        test->AIMove(player);
        player->ship.update(screen, player, player);
        test->ship.update(screen, test, player);
        if (player->interactEntityRocket(test)) {
            test->die();
        }

        // planets
        for (Planet planet : planets) {
            planet.update(screen, player);
            planet.applyGravityEntity(test);
        }

        if (moon.moveDelayCount >= moon.moveDelay - 1) {
            moon.applyGravity(screen, &earth);
            //earth.applyGravity(screen, &sun);
        }
    }
};