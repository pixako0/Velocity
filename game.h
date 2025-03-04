#pragma once

#include "Player.h"

namespace Tmpl8 {

class Surface;
class Player;
class Game
{
public:
    void SetTarget(Surface* surface) { screen = surface; player = new Player(); }
	void Init() {};
	void Shutdown() {};
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp(int key) { player->handleKeyUp(key); };
	void KeyDown(int key) { player->handleKeyDown(key); };

private:
	Surface* screen;
	Player* player;
};

}; // namespace Tmpl8