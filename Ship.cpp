#include "Ship.h"
#include "Player.h"

namespace Tmpl8
{
	static Sprite shipBase(new Surface("assets/Foozle_2DS0011_Void_MainShip/Main Ship/Main Ship - Bases/PNGs/Main Ship - Base - Full health.png"), 1);
	static Sprite shipEngine(new Surface("assets/Foozle_2DS0011_Void_MainShip/Main Ship/Main Ship - Engines/PNGs/Main Ship - Engines - Base Engine.png"), 1);
	static Sprite shipEngineIdle(new Surface("assets/Foozle_2DS0011_Void_MainShip/Main Ship/Main Ship - Engine Effects/PNGs/Main Ship - Engines - Base Engine - Idle.png"), 3);
	static Sprite shipEnginePowered(new Surface("assets/Foozle_2DS0011_Void_MainShip/Main Ship/Main Ship - Engine Effects/PNGs/Main Ship - Engines - Base Engine - Powering.png"), 4);

	void Ship::update(Surface* screen, Player* player)
	{
		int xPos = screen->GetWidthOffset() - shipBase.GetWidthOffset();
		int yPos = screen->GetHeightOffset() - shipBase.GetHeightOffset();

		if (player->moveRight || player->moveLeft || player->moveUp || player->moveDown)
		{
			shipEnginePowered.SetFrame(this->poweredFrameCount);
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
		else {
			shipEngineIdle.SetFrame(this->idleFrameCount);
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
		shipBase.Draw(screen, xPos, yPos);
	}
}