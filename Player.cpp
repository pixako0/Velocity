#include "Player.h"
#include <cstdio>
#include <algorithm>
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
		case 44:
			this->launchRocket();
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

	void Player::launchRocket()
	{
		Rocket rocket = Rocket();
		rocket.spawnX = this->x;
		rocket.spawnY = this->y;
		rocket.moveUp = true;
		rocket.initialize(this->ship.direction);

		rockets.push_back(rocket);
	}

	void Player::updateRockets(Surface* screen)
	{
		// end rocket
		this->rockets.erase(
			std::remove_if(this->rockets.begin(), this->rockets.end(),
				[](const Rocket& rocket) { return rocket.age > 500; }),
			this->rockets.end());

		// update rocket
		for (Rocket& rocket : this->rockets) {
			rocket.age++;
			rocket.move();
			rocket.ship.update(screen, &rocket, this);
		}
	}

	void Player::update(Surface* screen)
	{
		this->move();
		this->updateRockets(screen);
	}
}