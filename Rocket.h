#pragma once

#include "IEntity.h"
#include "RocketRender.h"

namespace Tmpl8 {
	class Rocket : public IEntity
	{
	public:
		Rocket(float spawnX, float spawnY, int direction) : IEntity(direction)
		{
			this->spawnX = spawnX;
			this->spawnY = spawnY;
			//this->ship = RocketRender(direction);
		}

		int GetMaxVelocity() const override { return 150; }
		float GetAcceleration() const override { return 0.6f; }

		float spawnX = 0;
		float spawnY = 0;
		int age = 0;

		float GetSpawnX() const override { return spawnX; }
		float GetSpawnY() const override { return spawnY; }

		void die();
		void initialize();

		RocketRender ship;
	};
}
