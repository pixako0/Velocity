#pragma once

#include "Ship.h"
#include "IEntity.h"

namespace Tmpl8 {
	class Planet;
	class Player : public IEntity
	{
	public:
		int GetMaxVelocity() const override { return 100; }
		void handleKeyUp(int key);
		void handleKeyDown(int key);
	private:
	};

}
