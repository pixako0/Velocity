#include "Ship.h"
#include "Player.h"

namespace Tmpl8
{
	static Sprite shipBase(new Surface("assets/ship_tilemaps/spaceship.png"), 8);
	static Sprite shipEngine(new Surface("assets/ship_tilemaps/engine.png"), 8);
	static Sprite shipEngineIdle(new Surface("assets/ship_tilemaps/flames idle.png"), 32);
	static Sprite shipEnginePowered(new Surface("assets/ship_tilemaps/flames supercharged.png"), 32);

	void Ship::update(Surface* screen, Player* player)
	{
		int xPos = screen->GetWidthOffset() - shipBase.GetWidthOffset();
		int yPos = screen->GetHeightOffset() - shipBase.GetHeightOffset();

		/// movement animation
		if (player->moveRight || player->moveLeft || player->moveUp || player->moveDown)
		{

			shipEnginePowered.SetFrame(this->poweredFrameCount*8);
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
			shipEngineIdle.SetFrame(this->idleFrameCount*8);
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

		shipEngine.Draw(screen, xPos, yPos);

		float angle = 45.0f;

		shipBase.Draw(screen, xPos, yPos);
	}
}