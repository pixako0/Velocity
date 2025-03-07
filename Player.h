#pragma once

namespace Tmpl8 {
	class Player
	{
	public:
		int x = 0;
		int y = 0;
		int speed = 2;

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
