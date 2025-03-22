#pragma once

#include "IEntity.h"
#include "RocketRender.h"

namespace Tmpl8 {
	class Rocket : public IEntity
	{
	public:
		int GetMaxVelocity() const override { return 150; }
		float GetAcceleration() const override { return 0.6f; }

		float spawnX = 0;
		float spawnY = 0;
		int age = 0;

		float GetSpawnX() const override { return spawnX; }
		float GetSpawnY() const override { return spawnY; }

		void die();
		void initialize(int direction);

		RocketRender ship;
	};
}
