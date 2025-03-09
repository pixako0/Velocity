#include "Player.h"
#include <cstdio>
#include <cmath>
#include "Planet.h"

namespace Tmpl8 {

	void Player::initialize()
	{
		this->x = this->spawnX;
		this->y = this->spawnY;
	}

	void Player::move()
	{
		// speed limiter
		if (this->velocityX > this->maxVelocity)
		{
			this->velocityX = this->maxVelocity;
		}
		else if (this->velocityX < -this->maxVelocity) {
			this->velocityX = -this->maxVelocity;
		}

		if (this->velocityY > this->maxVelocity)
		{
			this->velocityY = this->maxVelocity;
		}
		else if (this->velocityY < -this->maxVelocity) {
			this->velocityY = -this->maxVelocity;
		}

		// acceleration
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

	void Player::applyGravity(Planet* planet)
	{
		int xDistance = this->x - planet->x;
		int yDistance = this->y - planet->y;

		int distanceSquared = xDistance * xDistance + yDistance * yDistance;
		int planetSizeSquared = planet->planetSize * planet->planetSize;
		int gravityRangeSquared = planet->gravityRange * planet->gravityRange;

		// collision with planet
		if (distanceSquared < planetSizeSquared && planet->dieOnCollide) {
			this->die();
		}
		else if (distanceSquared < planetSizeSquared) {
			float distance = std::sqrt(distanceSquared);
			float normX = xDistance / distance;
			float normY = yDistance / distance;

			this->velocityX = normX;
			this->velocityY = normY;
		}

		// within gravity range
		else if (distanceSquared <= gravityRangeSquared) {
			float distance = std::sqrt(distanceSquared);
			float normX = xDistance / distance;
			float normY = yDistance / distance;

			this->velocityX += -0.5f * normX;
			this->velocityY += -0.5f * normY;
		}
	}

	void Player::die()
	{
		this->x = this->spawnX;
		this->y = this->spawnY;
		this->velocityX = 0;
		this->velocityY = 0;
	}
}