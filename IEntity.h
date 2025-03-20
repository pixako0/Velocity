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
		float acceleration = 0.6;

		float spawnX = -6080;
		float spawnY = -2000;

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
