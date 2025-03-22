#include "IEntity.h"
#include "Rocket.h"

namespace Tmpl8 {
	void IEntity::initialize()
	{
		this->x = this->GetSpawnX();
		this->y = this->GetSpawnY();
	}

	void IEntity::update(Surface* screen)
	{
		this->move();
	}

	void IEntity::move()
	{
		// speed limiter
		if (this->velocityX > this->GetMaxVelocity())
		{
			this->velocityX = this->GetMaxVelocity();
		}
		else if (this->velocityX < -this->GetMaxVelocity()) {
			this->velocityX = -this->GetMaxVelocity();
		}

		if (this->velocityY > this->GetMaxVelocity())
		{
			this->velocityY = this->GetMaxVelocity();
		}
		else if (this->velocityY < -this->GetMaxVelocity()) {
			this->velocityY = -this->GetMaxVelocity();
		}

		// acceleration
		this->x += this->velocityX / 10;
		this->y += this->velocityY / 10;


		// forwards
		if (moveUp) {
			switch (ship.direction) {
			case 0:
				this->velocityY -= this->GetAcceleration();
				break;
			case 1:
				this->velocityY -= this->GetAcceleration() / 2;
				this->velocityX += this->GetAcceleration() / 2;
				break;
			case 2:
				this->velocityX += this->GetAcceleration();
				break;
			case 3:
				this->velocityX += this->GetAcceleration() / 2;
				this->velocityY += this->GetAcceleration() / 2;
				break;
			case 4:
				this->velocityY += this->GetAcceleration();
				break;
			case 5:
				this->velocityY += this->GetAcceleration() / 2;
				this->velocityX -= this->GetAcceleration() / 2;
				break;
			case 6:
				this->velocityX -= this->GetAcceleration();
				break;
			case 7:
				this->velocityX -= this->GetAcceleration() / 2;
				this->velocityY -= this->GetAcceleration() / 2;
				break;
			}
		}
	}

	void IEntity::die()
	{
		this->x = this->GetSpawnX();
		this->y = this->GetSpawnY();
		this->velocityX = 0;
		this->velocityY = 0;
	}
}