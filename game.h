#pragma once

#include "Player.h"
#include "Planet.h"
#include "Background.h"
#include "Ship.h"
#include "Enemy.h"
#include <list>

namespace Tmpl8 {

class Surface;
class Player;
class Planet;
class Enemy;
class Game
{
public:
	void SetTarget(Surface* surface) { 
		screen = surface; 
		player = new Player();
		player->ship = *new Ship();
	}
	void Init();
	void Shutdown() {};
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp(int key) { player->handleKeyUp(key); };
	void KeyDown(int key) { player->handleKeyDown(key); };
	void showScore();

	void CreateEnemies(int count);

private:
	Surface* screen;
	Player* player;
	Ship* ship;
	Enemy* test;
	std::list<Planet> planets;
	std::list<Enemy*> enemies;
};

}; // namespace Tmpl8