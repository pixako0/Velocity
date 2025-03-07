#include "Planet.h"

namespace Tmpl8
{
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