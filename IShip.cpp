#include "IShip.h"
#include "IEntity.h"

namespace Tmpl8
{
	static Sprite shipBase(new Surface("assets/ship_tilemaps/spaceship.png"), 8);
	static Sprite shipEngine(new Surface("assets/ship_tilemaps/engine.png"), 8);
	static Sprite shipEngineIdle(new Surface("assets/ship_tilemaps/flames idle.png"), 32);
	static Sprite shipEnginePowered(new Surface("assets/ship_tilemaps/flames supercharged.png"), 32);

	void IShip::update(Surface* screen, IEntity* entity)
	{
		int xPos = screen->GetWidthOffset() - shipBase.GetWidthOffset();
		int yPos = screen->GetHeightOffset() - shipBase.GetHeightOffset();

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

		/// movement animation
		if (entity->moveUp)
		{

			shipEnginePowered.SetFrame(this->poweredFrameCount * 8 + this->direction);
			shipEnginePowered.Draw(screen, xPos, yPos);
			this->poweredFrameDelayCount++;
			if (this->poweredFrameDelayCount >= this->poweredFrameDelay) {
				this->poweredFrameCount++;
				this->poweredFrameDelayCount = 0;
				if (this->poweredFrameCount >= this->poweredFrame) {
					this->poweredFrameCount = 0;
				}
			}
		}

		// idle animation
		else {
			shipEngineIdle.SetFrame(this->idleFrameCount * 8 + this->direction);
			shipEngineIdle.Draw(screen, xPos, yPos);
			this->idleFrameDelayCount++;
			if (this->idleFrameDelayCount >= this->idleFrameDelay) {
				this->idleFrameCount++;
				this->idleFrameDelayCount = 0;
				if (this->idleFrameCount >= this->idleFrame) {
					this->idleFrameCount = 0;
				}
			}
		}

		shipEngine.SetFrame(this->direction);
		shipEngine.Draw(screen, xPos, yPos);

		shipBase.SetFrame(this->direction);
		shipBase.Draw(screen, xPos, yPos);
	}
}