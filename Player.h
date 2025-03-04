#pragma once

namespace Tmpl8 {
	class Player
	{
	public:
		int x = 50;
		int y = 50;
		int speed = 2;

		bool moveRight = false;
		bool moveLeft = false;
		bool moveUp = false;
		bool moveDown = false;

		void move();
		void handleKeyUp(int key);
		void handleKeyDown(int key);
	};

}
