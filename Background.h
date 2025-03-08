#pragma once

namespace Tmpl8
{
	class Surface;
	class Player;
	class Background
	{
	public:
		int slowness = 2;
		void update(Surface* screen, Player* player);
	};
}
