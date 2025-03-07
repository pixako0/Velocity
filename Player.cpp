#include "Player.h"
#include <cstdio>

namespace Tmpl8 {

	void Player::move()
	{
		if (moveRight) {
			this->x += this->speed;
		}
		if (moveLeft) {
			this->x -= this->speed;
		}
		if (moveUp) {
			this->y -= this->speed;
		}
		if (moveDown) {
			this->y += this->speed;
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

	void Player::applyGravity(int gravityRange, int gravityX, int gravityY)
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
		printf("Distance: %d\n", totalDistance);
		if (totalDistance <= gravityRange) {
			if (xDistance < 0) {
				this->x += 0.5;
			}
			else if (xDistance > 0) {
				this->x -= 0.5;
			}

			if (yDistance < 0) {
				this->y += 0.5;
			}
			else if (yDistance > 0) {
				this->y -= 0.5;
			}
		}
	}
}