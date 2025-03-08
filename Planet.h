namespace Tmpl8 {
	class Player;
	class Sprite;
	class Surface;
	class Planet
	{
	public:
		int x = 0;
		int y = 0;

		int gravityRange = 200;
		int planetsize = 65;

		int frame = 100;
		int frameCount = 0;
		int frameDelay = 4;
		int frameDelayCount = 0;

		const char* asset = "assets/planets/planet.png";

		void initialize();
		void update(Surface* screen, Player* player);

	private:
		Sprite* planetSprite = nullptr;
		void nextFrame();
	};
}
