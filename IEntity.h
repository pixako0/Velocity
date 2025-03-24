#pragma once

#include "IShip.h"
#include <list>

namespace Tmpl8 {
	class Planet;
	class IEntity
	{
	public:
		IEntity(int direction = 0) : ship(direction) {}
		virtual ~IEntity() = default;

		float x = 0;
		float y = 0;
		virtual float GetAcceleration() const = 0;

		virtual float GetSpawnX() const = 0;
		virtual float GetSpawnY() const = 0;

		virtual int GetMaxVelocity() const = 0;

		float velocityX = 0;
		float velocityY = 0;

		bool moveRight = false;
		bool moveLeft = false;
		bool moveUp = false;
		bool moveDown = false;

		void update(Surface* screen);
		void move();
		void die();

		void initialize();

		IShip ship;
	};
}
