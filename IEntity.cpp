#include "IEntity.h"

namespace Tmpl8 {
	void IEntity::initialize()
	{
		this->x = this->spawnX;
		this->y = this->spawnY;
	}

	void IEntity::move()
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

		// forwards
		if (moveUp) {
			switch (ship.direction) {
			case 0:
				this->velocityY -= this->acceleration;
				break;
			case 1:
				this->velocityY -= this->acceleration / 2;
				this->velocityX += this->acceleration / 2;
				break;
			case 2:
				this->velocityX += this->acceleration;
				break;
			case 3:
				this->velocityX += this->acceleration / 2;
				this->velocityY += this->acceleration / 2;
				break;
			case 4:
				this->velocityY += this->acceleration;
				break;
			case 5:
				this->velocityY += this->acceleration / 2;
				this->velocityX -= this->acceleration / 2;
				break;
			case 6:
				this->velocityX -= this->acceleration;
				break;
			case 7:
				this->velocityX -= this->acceleration / 2;
				this->velocityY -= this->acceleration / 2;
				break;
			}
		}
	}

	void IEntity::die()
	{
		this->x = this->spawnX;
		this->y = this->spawnY;
		this->velocityX = 0;
		this->velocityY = 0;
	}
}