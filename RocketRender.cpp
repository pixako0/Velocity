#include "RocketRender.h"
#include "IEntity.h"
#include "Player.h"

namespace Tmpl8 
{
	static Sprite rocket(new Surface("assets/Foozle_2DS0011_Void_MainShip/Main ship weapons/PNGs/Main ship weapon - Projectile - Rocket.png"), 3);

	void RocketRender::update(Surface* screen, IEntity* entity, IEntity* player)
	{
		int xPos = screen->GetWidthOffset() - rocket.GetWidthOffset() - (player->x - entity->x);
		int yPos = screen->GetHeightOffset() - rocket.GetHeightOffset() - (player->y - entity->y);

		if (this->directionTimeout > this->directionTimeoutCount) {
			this->directionTimeoutCount++;
		}
		else {
			this->directionTimeoutCount = 0;
			if (entity->moveRight) {
				this->direction++;
				if (this->direction >= 8) {
					this->direction = 0;
				}
			}
			if (entity->moveLeft) {
				this->direction--;
				if (this->direction < 0) {
					this->direction = 7;
				}
			}
		}

		rocket.Draw(screen, xPos, yPos);
	}
}