#pragma once

#include "Ship.h"
#include "IEntity.h"

namespace Tmpl8 {
	class Planet;
	class Player : public IEntity
	{
	public:
		void handleKeyUp(int key);
		void handleKeyDown(int key);
	private:
	};

}
