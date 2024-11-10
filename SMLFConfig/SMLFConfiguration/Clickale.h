#pragma once
#include "Alien.h"
#include "Cross.h"
#include <SFML/Graphics.hpp>

class Clickale
{
public:
	Clickale();
	void Play();

private:
	RenderWindow window;
	Cross cross;
	Alien alien;
	int aliensDefeated;
	int maxScore = 5;

	sf::Texture crossTex;
	sf::Texture alienTex;
};



