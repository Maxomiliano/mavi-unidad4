#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cross
{
public:
	Cross();
	void UpdatePosition(Vector2f position);
	void Draw(RenderWindow& window);
private:
	Texture crossTex;
	Sprite crossSpr;
};

