#include "Background.h"
#include "surface.h"
#include "Player.h"

namespace Tmpl8
{
	static Sprite background(new Surface("assets/space/PNG/Space_Stars6.png"), 1);

	void Background::update(Surface* screen, Player* player)
	{
		int x = 0;
		int y = 0;

		for (int i = 0; i < 2000; i += background.GetWidth())
		{
			for (int j = 0; j < 1000; j += background.GetHeight())
			{
				x = (player->x / this->slowness) / background.GetWidth();
				x *= background.GetWidth();
				y = (player->y / this->slowness) / background.GetHeight();
				y *= background.GetHeight();
				background.Draw(screen, x + i - player->x / this->slowness - screen->GetWidthOffset(), y + j - player->y / this->slowness - screen->GetHeightOffset());
			}
		}
	}
}