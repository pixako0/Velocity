#include "Planet.h"
#include "surface.h"
#include "IEntity.h"
#include <cstdio>
#include <cmath>

namespace Tmpl8
{
	void Planet::initialize()
	{
		planetSprite = new Sprite(new Surface((char*)this->asset), this->frame);
		this->gravityRange = this->planetSize * 3;
		this->gravityStrength = -0.3 * (this->planetSize / 100);
		if (this->gravityStrength > -0.3) {
			this->gravityStrength = -0.1;
		}
	}

	void Planet::update(Surface* screen, IEntity* entity)
	{
		planetSprite->SetFrame(this->frameCount);
		planetSprite->Draw(screen, this->x - entity->x + screen->GetWidthOffset() - planetSprite->GetWidthOffset(), this->y - entity->y + screen->GetHeightOffset() - planetSprite->GetHeightOffset());
		this->nextFrame();
		this->nametag(screen, entity);
		this->applyGravityEntity(entity);
		
		this->moveDelayCount++;
		if (this->moveDelayCount >= this->moveDelay) {
			this->move();
			this->moveDelayCount = 0;
		}
	}

	void Planet::move()
	{
		this->x += this->velocityX / 10;
		this->y += this->velocityY / 10;
	}

	void Planet::nametag(Surface* screen, IEntity* entity)
	{
		int planetScreenX = this->x - entity->x + screen->GetWidthOffset();
		if (planetScreenX < 50) {
			planetScreenX = 50;
		}
		else if (planetScreenX > screen->GetWidth() - 50) {
			planetScreenX = screen->GetWidth() - 50;
		}

		int planetScreenY = this->y - entity->y + screen->GetHeightOffset();
		if (planetScreenY < 50) {
			planetScreenY = 50;
		}
		else if (planetScreenY > screen->GetHeight() - 50)
		{
			planetScreenY = screen->GetHeight() - 50;
		}

		screen->Print(this->name, planetScreenX, planetScreenY, 0xFFFFFF);
	}

	void Planet::nextFrame()
	{
		this->frameDelayCount++;
		if (this->frameDelayCount >= this->frameDelay) {
			this->frameCount++;
			this->frameDelayCount = 0;
		}

		if (this->frameCount >= this->frame) {
			this->frameCount = 0;
		}
	}

	void Planet::applyGravity(Surface* screen, Planet* planet)
	{
		int xDistance = this->x - planet->x;
		int yDistance = this->y - planet->y;

		int distanceSquared = xDistance * xDistance + yDistance * yDistance;
		int planetSizeSquared = planet->planetSize * planet->planetSize;
		int gravityRangeSquared = planet->gravityRange * planet->gravityRange;

		float distance = std::sqrt(distanceSquared);
		float normX = xDistance / distance;
		float normY = yDistance / distance;

		// collision with planet
		if (distanceSquared < planetSizeSquared) {
			this->velocityX = normX;
			this->velocityY = normY;
		}

		// apply gravity
		else {
			this->velocityX += planet->gravityStrength * normX / 3;
			this->velocityY += planet->gravityStrength * normY / 3;
		}
	}

	void Planet::applyGravityEntity(IEntity* entity)
	{
		int xDistance = entity->x - this->x;
		int yDistance = entity->y - this->y;

		int distanceSquared = xDistance * xDistance + yDistance * yDistance;
		int planetSizeSquared = this->planetSize * this->planetSize;
		int gravityRangeSquared = this->gravityRange * this->gravityRange;

		float distance = std::sqrt(distanceSquared);
		float normX = xDistance / distance;
		float normY = yDistance / distance;

		// collision with planet
		if (distanceSquared < planetSizeSquared && this->dieOnCollide) {
			entity->die();
		}
		else if (distanceSquared <= planetSizeSquared) {
			entity->velocityX = normX;
			entity->velocityY = normY;
		}

		// within gravity range
		else if (distanceSquared <= gravityRangeSquared) {
			entity->velocityX += this->gravityStrength * normX;
			entity->velocityY += this->gravityStrength * normY;
		}
	}
}