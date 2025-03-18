#include "Background.h"
#include "surface.h"
#include "Player.h"
#include <cmath>
#include <cstdio>

namespace Tmpl8
{
	static Sprite background(new Surface("assets/space/PNG/Space_Stars2.png"), 4);

	void Background::update(Surface* screen, Player* player)
	{
		this->border(player);

		int x = 0;
		int y = 0;

		int tileX = 0;
		int tileY = 0;
		int tileCount = 0;

		for (int i = 0; i < 2000; i += background.GetWidth())
		{
			for (int j = 0; j < 1000; j += background.GetHeight())
			{
				x = (player->x / this->slowness) / background.GetWidth();
				x *= background.GetWidth();
				y = (player->y / this->slowness) / background.GetHeight();
				y *= background.GetHeight();

				tileX = (x + i) / background.GetWidth();
				tileY = (y + j) / background.GetHeight();
				tileCount = tileX + tileY;
				if (tileCount < 0) {
					tileCount = -tileCount;
				}

				while (tileCount > 3) {
					tileCount -= 3;
				}

				background.SetFrame(tileCount);
				background.Draw(screen, x + i - player->x / this->slowness - screen->GetWidthOffset(), y + j - player->y / this->slowness - screen->GetHeightOffset());
			}
		}
	}

	void Background::border(Player* player)
	{
		if (player->x >= 100000 || player->x <= -100000 || player->y >= 100000 || player->y <= -100000)
		{
			player->velocityY = 0;
			player->velocityX = 0;
			player->x = player->spawnX;
			player->y = player->spawnY;
		}
	}
}