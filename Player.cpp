#include "Player.h"
#include <cstdio>

namespace Tmpl8 {

	void Player::move()
	{
		this->x += this->velocityX / 10;
		this->y += this->velocityY / 10;

		if (moveRight) {
			this->velocityX += this->acceleration;
		}
		if (moveLeft) {
			this->velocityX -= this->acceleration;
		}
		if (moveUp) {
			this->velocityY -= this->acceleration;
		}
		if (moveDown) {
			this->velocityY += this->acceleration;
		}

		//printf("R:%d | L:%d | U:%d | D:%d\n", moveRight, moveLeft, moveUp, moveDown);
	}

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

	void Player::applyGravity(int planetSize, int gravityRange, int gravityX, int gravityY)
	{
		int xDistance = this->x - gravityX;
		int xDistanceC = xDistance;
		if (xDistance < 0) {
			xDistanceC = -xDistance;
		}

		int yDistance = this->y - gravityY;
		int yDistanceC = yDistance;
		if (yDistance < 0) {
			yDistanceC = -yDistanceC;
		}

		int totalDistance = (yDistanceC + xDistanceC) / 2;
		if (totalDistance < planetSize) {
			this->velocityX = (xDistance < 0) ? -1 : 1;
			this->velocityY = (yDistance < 0) ? -1 : 1;
		} 
		else if (totalDistance <= gravityRange) {
			this->velocityX += (xDistance < 0) ? 0.5 : -0.5;
			this->velocityY += (yDistance < 0) ? 0.5 : -0.5;
		}
	}
}