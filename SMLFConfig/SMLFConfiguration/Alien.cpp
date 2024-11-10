#include "Alien.h"
#include <cstdlib>

Alien::Alien()
{
	alienTex.loadFromFile("et.png");
	alienSpr.setTexture(alienTex);
	alienSpr.setOrigin(64, 64);
	isVisible = true;
}

void Alien::Spawn(Vector2u windowSize)
{
	float x = rand() % windowSize.x;
	float y = rand() % windowSize.y;
	alienSpr.setPosition(x, y);
	isVisible = true;
}

bool Alien::IsClicked(Vector2f crossPosition)
{
	if (isVisible && alienSpr.getGlobalBounds().contains(crossPosition))
	{
		isVisible = false;
		return true;
	}
	return false;
}

void Alien::Draw(RenderWindow& window)
{
	if (isVisible)
	{
		window.draw(alienSpr);
	}
}

bool Alien::IsVisible() const
{
	return IsVisible;
}