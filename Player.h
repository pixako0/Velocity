#pragma once

namespace Tmpl8 {
	class Player
	{
	public:
		float x = 0;
		float y = 0;
		int acceleration = 2;

		float velocityX = 0;
		float velocityY = 0;

		bool moveRight = false;
		bool moveLeft = false;
		bool moveUp = false;
		bool moveDown = false;

		void move();
		void applyGravity(int gravityRange, int gravityX, int gravityY);
		void handleKeyUp(int key);
		void handleKeyDown(int key);
	};

}
