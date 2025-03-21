#pragma once

#include "IShip.h"

namespace Tmpl8 {
	class Planet;
	class IEntity
	{
	public:
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

		void move();
		void die();

		void initialize();

		IShip ship;
	private:
	};
}
