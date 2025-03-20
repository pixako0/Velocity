namespace Tmpl8 {
	class IEntity;
	class Sprite;
	class Surface;
	class Planet
	{
	public:
		char* name = "";
		bool dieOnCollide = false;

		float x = 0;
		float y = 0;

		float velocityX = 0;
		float velocityY = 0;

		int gravityRange = 0;
		float gravityStrength = 0;
		int planetSize = 0;

		int frame = 1;
		int frameDelay = 4;

		const char* asset = "assets/planets/default.png";

		void initialize();
		void update(Surface* screen, IEntity* entity);
		void applyGravity(Surface* screen, Planet* planet);
		void applyGravityEntity(IEntity* entity);

		int moveDelay = 100;
		int moveDelayCount = 0;

	private:
		int frameCount = 0;
		int frameDelayCount = 0;

		Sprite* planetSprite = nullptr;

		void nextFrame();
		void nametag(Surface* screen, IEntity* entity);
		void move();
	};
}
