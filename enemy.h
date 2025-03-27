#pragma once
#include "IEntity.h"
#include <list>
#include "Rocket.h"

namespace Tmpl8 {
	class Enemy : public IEntity
	{
	public:
		Enemy() {}
		int GetMaxVelocity() const override { return 30; }
		float GetAcceleration() const override { return 0.6f; }

		float GetSpawnX() const override { return -6080; }
		float GetSpawnY() const override { return -2000; }

		void AIMove(IEntity* target);

		void launchRocket();
		void updateRockets(Surface* screen, IEntity* player);
		bool interactEntityRocket(IEntity* entity);

		void update(Surface* screen, IEntity* player);

		std::list<Rocket> rockets;
	private:
		int moveGoal = 0;
		int targetRange = 500;
		void MoveToSpawn();

		int rocketLaunchCooldown = 20;
		int rocketLaunchCooldownCount = 0;
	};
}
