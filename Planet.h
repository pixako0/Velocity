namespace Tmpl8 {
	class Player;
	class Sprite;
	class Surface;
	class Planet
	{
	public:
		int x = 0;
		int y = 0;

		int gravityRange = 0;
		int planetSize = 0;

		int frame = 1;
		int frameDelay = 4;

		const char* asset = "assets/planets/default.png";

		void initialize();
		void update(Surface* screen, Player* player);

	private:
		int frameCount = 0;
		int frameDelayCount = 0;
		Sprite* planetSprite = nullptr;
		void nextFrame();
	};
}
