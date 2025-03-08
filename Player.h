#pragma once

#include "Ship.h"

namespace Tmpl8 {
	class Planet;
	class Player
	{
	public:
		float x = 100;
		float y = 100;
		float acceleration = 0.6;

		int maxVelocity = 100;

		float velocityX = 21;
		float velocityY = -21;

		bool moveRight = false;
		bool moveLeft = false;
		bool moveUp = false;
		bool moveDown = false;

		void move();
		void applyGravity(Planet* planet);
		void handleKeyUp(int key);
		void handleKeyDown(int key);
	};

}
