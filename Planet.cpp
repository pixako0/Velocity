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
		this->nametag(screen, player);
	}

	void Planet::nametag(Surface* screen, Player* player)
	{
		int planetScreenX = this->x - player->x + screen->GetWidthOffset();
		if (planetScreenX < 50) {
			planetScreenX = 50;
		}
		else if (planetScreenX > screen->GetWidth() - 50) {
			planetScreenX = screen->GetWidth() - 50;
		}

		int planetScreenY = this->y - player->y + screen->GetHeightOffset();
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
}