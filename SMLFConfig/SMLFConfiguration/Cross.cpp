#include "Cross.h"

Cross::Cross()
{
	crossTex.loadFromFile("crosshair.png");
	crossSpr.setTexture(crossTex);
	crossSpr.setOrigin(64, 64);
}

void Cross::UpdatePosition(Vector2f position)
{
	crossSpr.setPosition(position);
}

void Cross::Draw(RenderWindow& window)
{
	window.draw(crossSpr);
}