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

		int playerX = player->x / this->slowness;
		int playerY = player->y / this->slowness;

		int x = playerX / background.GetWidth() * background.GetWidth();
		int y = playerY / background.GetHeight() * background.GetHeight();

		for (int i = 0; i < 2000; i += background.GetWidth())
		{
			for (int j = 0; j < 1000; j += background.GetHeight())
			{
				int tileX = (x + i) / background.GetWidth();
				int tileY = (y + j) / background.GetHeight();
				int frame = tileX + tileY;
				frame = std::abs(frame) % 3;

				background.SetFrame(frame);
				background.Draw(screen, x + i - playerX - screen->GetWidthOffset(), y + j - playerY - screen->GetHeightOffset());
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