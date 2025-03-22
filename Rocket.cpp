#include "Rocket.h"

namespace Tmpl8 
{
	void Rocket::initialize(int direction)
	{
		this->x = this->GetSpawnX();
		this->y = this->GetSpawnY();

		this->ship.direction = direction;
	}

	void Rocket::die()
	{
		return;
	}
}