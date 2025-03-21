#pragma once

#include "Ship.h"
#include "IEntity.h"

namespace Tmpl8 {
	class Planet;
	class Player : public IEntity
	{
	public:
		int GetMaxVelocity() const override { return 100; }
		float GetAcceleration() const override { return 0.6f; }

		float GetSpawnX() const override { return -6080; }
		float GetSpawnY() const override { return -2000; }

		void handleKeyUp(int key);
		void handleKeyDown(int key);
	private:
	};

}
