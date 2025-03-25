#include "Rocket.h"
#include <cmath>

namespace Tmpl8 
{
	void Rocket::initialize()
	{
		this->x = this->GetSpawnX();
		this->y = this->GetSpawnY();
	}

	void Rocket::die()
	{
		return;
	}

	bool Rocket::checkCollision(IEntity* entity, int colissionRange)
	{
		int xDistance = entity->x - this->x;
		int yDistance = entity->y - this->y;

		int distanceSquared = xDistance * xDistance + yDistance * yDistance;
		int colissionRangeSquared = colissionRange * colissionRange;

		float distance = std::sqrt(distanceSquared);
		float normX = xDistance / distance;
		float normY = yDistance / distance;

		// collision with entity
		if (distanceSquared < colissionRangeSquared) {
			return true;
		}
		return false;
	}
}