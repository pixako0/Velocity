#pragma once

#include "Ship.h"
#include "IEntity.h"
#include <list>
#include "Rocket.h"

namespace Tmpl8 {
	class Planet;
	class Player : public IEntity
	{
	public:
		Player() {}
		int GetMaxVelocity() const override { return 100; }
		float GetAcceleration() const override { return 0.6f; }

		float GetSpawnX() const override { return -6080; }
		float GetSpawnY() const override { return -2000; }

		void handleKeyUp(int key);
		void handleKeyDown(int key);

		void launchRocket();
		void updateRockets(Surface* screen);
		bool interactEntityRocket(IEntity* entity);

		void update(Surface* screen);
		void die();

		std::list<Rocket> rockets;
		int score = 0;
		int lastScore = 0;
		bool gameOver = false;
	private:
		void updateScore();
		void renderScore(Surface* screen);
	};

}
