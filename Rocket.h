#pragma once

#include "IEntity.h"
#include "RocketRender.h"

namespace Tmpl8 {
	class Rocket : public IEntity
	{
	public:
		Rocket(float spawnX, float spawnY, int direction, float velocityX, float velocityY) : IEntity(direction, velocityX, velocityY), ship(direction)
		{
			this->spawnX = spawnX;
			this->spawnY = spawnY;
		}

		int GetMaxVelocity() const override { return 100; }
		float GetAcceleration() const override { return 10.0f; }

		float spawnX = 0;
		float spawnY = 0;
		int age = 0;

		float GetSpawnX() const override { return spawnX; }
		float GetSpawnY() const override { return spawnY; }

		bool checkCollision(IEntity* entity, int colissionRange);

		void die();
		void initialize();

		RocketRender ship;
	};
}
