#include "Rocket.h"

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
}