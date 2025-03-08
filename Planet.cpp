#include "Planet.h"
#include "surface.h"
#include "Player.h"

namespace Tmpl8
{
	void Planet::initialize()
	{
		planetSprite = new Sprite(new Surface((char*)this->asset), this->frame);
		this->gravityRange = this->planetSize * 3;
	}

	void Planet::update(Surface* screen, Player* player)
	{
		planetSprite->SetFrame(this->frameCount);
		planetSprite->Draw(screen, this->x - player->x + screen->GetWidthOffset() - planetSprite->GetWidthOffset(), this->y - player->y + screen->GetHeightOffset() - planetSprite->GetHeightOffset());
		this->nextFrame();
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
}