#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Alien
{
public: Alien();
	  void Spawn(Vector2u windowSize);
	  bool IsClicked(Vector2f crossPosition);
	  void Draw(RenderWindow& window);
	  bool IsVisible() const;
private:
	Texture alienTex;
	Sprite alienSpr;
	bool isVisible;
};

