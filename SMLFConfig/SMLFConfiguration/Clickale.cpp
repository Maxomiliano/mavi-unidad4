#include "Clickale.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Clickale::Clickale()
{
	Event evt;
	Mouse mouse;
	Texture _crosshairTex;
	Texture _alienTex;
	Sprite* _alienSpr = new Sprite();
	Sprite* _crosshairSpr = new Sprite();

	float scaleX;
	float scaleY;
	float heightCross;
	float widthCross;
	float heightAlien;
	float widthAlien;
	bool isAlienVisible = true;

	_crosshairTex.loadFromFile("crosshair.png");
	_alienTex.loadFromFile("et.png");
	_crosshairSpr->setTexture(_crosshairTex);
	_alienSpr->setTexture(_alienTex);
	_crosshairSpr->setOrigin(64, 64);
	_alienSpr->setOrigin(64, 64);
	_alienSpr->setPosition(400, 300);
	_crosshairSpr->setPosition(400, 300);

	widthCross = (float)_crosshairTex.getSize().x;
	heightCross = (float)_crosshairTex.getSize().y;
	widthAlien = (float)_alienTex.getSize().x;
	heightAlien = (float)_alienTex.getSize().y;
	
	scaleX = widthCross / widthAlien;
	scaleY = heightCross / heightAlien;
	_alienSpr->setScale(scaleX, scaleY);

	RenderWindow window(VideoMode(800, 600, 32), "Clickale");

	//Vector2u windowSize = window.getSize();

	while (window.isOpen())
	{
		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				_crosshairSpr->setPosition(evt.mouseMove.x, evt.mouseMove.y);
			case Event::MouseButtonPressed:
				if (mouse.isButtonPressed(mouse.Left) && isAlienVisible)
				{
					if (_alienSpr->getGlobalBounds().contains(evt.mouseButton.x, evt.mouseButton.y))
					{
						isAlienVisible = false;
					}
				}
				break;
			}
		}
		window.clear();
		if(isAlienVisible)
			window.draw(*_alienSpr);
		window.draw(*_crosshairSpr);
		window.display();
	}
}