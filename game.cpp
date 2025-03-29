#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <string>

namespace Tmpl8
{
    Background background;

    Planet sun;
    Planet mercury;
    Planet venus;
    Planet earth;
    Planet moon;

    void Game::CreateEnemies(int count)
    {
        for (int i = 0; i < count; i++) {
            Enemy* enemy = new Enemy();
            enemy->initialize();
            enemy->ship = IShip(0);
            enemies.push_front(enemy);
        }
    }

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
        planets.push_front(mercury);

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

        this->CreateEnemies(10);

        background = Background();
    }

    void Game::showScore()
    {
		screen->Centre(const_cast<char*>("You died"), screen->GetHeightOffset() - 50, 0xffffff);
		screen->Centre(const_cast<char*>("Press enter to restart"), screen->GetHeightOffset() - 25, 0xffffff);
        screen->Centre(const_cast<char*>(("Final score: " + std::to_string(player->lastScore)).c_str()), screen->GetHeightOffset(), 0xffffff);
    }

    void Game::Tick(float deltaTime)
    {
		if (player->gameOver) {
			showScore();
			return;
		}

        screen->Clear(0);

        // background
        background.update(screen, player);

        // planets
        for (Planet planet : planets) {
            planet.update(screen, player);
            for (Enemy* enemy : enemies) {
                planet.applyGravityEntity(enemy);
            }
        }

        if (moon.moveDelayCount >= moon.moveDelay - 1) {
            moon.applyGravity(screen, &earth);
            //earth.applyGravity(screen, &sun);
        }

        // player
        player->update(screen);

        // enemies
        for (Enemy* enemy : enemies) {
            enemy->update(screen, player);
            enemy->AIMove(player);
            enemy->ship.update(screen, enemy, player);

            if (enemy->interactEntityRocket(player)) {
                player->gameOver = true;
				player->lastScore = player->score;
				for (Enemy* enemy : enemies) {
					delete enemy;
				}
				enemies.clear();
				this->CreateEnemies(10);
                player->die();
                return;
            }

            if (player->interactEntityRocket(enemy)) {
                enemy->die();
                this->CreateEnemies(1);
            }
        }

        player->ship.update(screen, player, player);
    }
};