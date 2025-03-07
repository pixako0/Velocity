#pragma once

namespace Tmpl8 {
	class Player
	{
	public:
		float x = 100;
		float y = 100;
		int acceleration = 2;

		float velocityX = 20;
		float velocityY = -20;

		bool moveRight = false;
		bool moveLeft = false;
		bool moveUp = false;
		bool moveDown = false;

		void move();
		void applyGravity(int planetSize, int gravityRange, int gravityX, int gravityY);
		void handleKeyUp(int key);
		void handleKeyDown(int key);
	};

}
