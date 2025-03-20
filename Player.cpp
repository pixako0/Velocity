#include "Player.h"
#include <cstdio>
#include <cmath>
#include "Planet.h"

namespace Tmpl8 {
	void Player::handleKeyUp(int key)
	{
		switch (key)
		{
		case 7:
			this->moveRight = false;
			break;
		case 26:
			this->moveUp = false;
			break;
		case 22:
			this->moveDown = false;
			break;
		case 4:
			this->moveLeft = false;
			break;

		case 79:
			this->moveRight = false;
			break;
		case 82:
			this->moveUp = false;
			break;
		case 81:
			this->moveDown = false;
			break;
		case 80:
			this->moveLeft = false;
			break;
		}
	}

	void Player::handleKeyDown(int key)
	{
		//printf("%d\n", key);
		switch (key)
		{
		case 7:
			this->moveRight = true;
			break;
		case 26:
			this->moveUp = true;
			break;
		case 22:
			this->moveDown = true;
			break;
		case 4:
			this->moveLeft = true;
			break;

		case 79:
			this->moveRight = true;
			break;
		case 82:
			this->moveUp = true;
			break;
		case 81:
			this->moveDown = true;
			break;
		case 80:
			this->moveLeft = true;
			break;
		}
	}
}