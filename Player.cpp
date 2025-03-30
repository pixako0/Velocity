#include "Player.h"
#include <cstdio>
#include <algorithm>
#include <cmath>
#include "Planet.h"
#include <iostream>
#include <cstring>
#include <string>

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
		case 40:
			this->gameOver = false;
			break;
		}
	}

	void Player::launchRocket()
	{
		Rocket rocket = Rocket(this->x, this->y, this->ship.direction);
		rocket.moveUp = true;
		rocket.initialize();

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

	bool Player::interactEntityRocket(IEntity* entity)
	{
		int radius = 12;
		bool colliding = false;

		this->rockets.erase(
			std::remove_if(this->rockets.begin(), this->rockets.end(),
				[&colliding, entity, radius](Rocket& rocket) {
					if (rocket.checkCollision(entity, radius)) {
						colliding = true;
						return true;
					}
					return false;
				}),
			this->rockets.end());

		if (colliding) {
			this->updateScore();
		}

		return colliding;
	}



	void Player::update(Surface* screen)
	{
		this->move();
		this->updateRockets(screen);
		this->renderScore(screen);
	}

	void Player::renderScore(Surface* screen)
	{
		const char* text = "Score: ";
		char scoreBuffer[50];
		strcpy(scoreBuffer, text);
		strcat(scoreBuffer, std::to_string(this->score).c_str());
		screen->Print(scoreBuffer, 25, 10, 0xFFFFFF);
		
		char coordBuffer[50];
		std::sprintf(coordBuffer, "X: %d Y: %d", static_cast<int>(this->x), static_cast<int>(this->y));
		screen->Print(coordBuffer, 100, 10, 0xFFFFFF);
	}

	void Player::updateScore()
	{
		this->score++;
	}

    void Player::die()
    {
        IEntity::die();
        this->score = 0;
    }
}