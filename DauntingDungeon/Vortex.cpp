#include "Vortex.h"
#include "Animation.h"

Vortex::Vortex(Vector2 pos, VortexType t) :
	GameObject("DauntingDungeon/Assets/vortex.png", pos, vortex)
{
	inverseMass = 0;

	srcRect.h = 48;
	srcRect.w = 50;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 150;
	destRect.w = 150;

	animated = true;
	anim = new Animation(Vector2(0, 0), 8, 1000);
}
