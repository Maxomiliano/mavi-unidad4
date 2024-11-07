#include "Atrapado.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Atrapado::Atrapado()
{
	Event evt;
	Mouse mouse;
	Texture _ysquareTex;
	Texture _rcircleTex;
	Sprite* _currentSpr = new Sprite();
	bool isSquare = true;

	float scaleX;
	float scaleY;
	float heightSquare;
	float heightCircle;
	float widthSquare;
	float widthCircle;

	float movementPos = 5.0f;


	_ysquareTex.loadFromFile("cuad_yellow.png");
	_rcircleTex.loadFromFile("rcircle.png");
	_currentSpr->setTexture(_ysquareTex);
	_currentSpr->setPosition(500, 500);

	
	widthSquare = (float)_ysquareTex.getSize().x;
	heightSquare = (float)_ysquareTex.getSize().y;
	widthCircle =  (float)_rcircleTex.getSize().x;
	heightCircle = (float)_rcircleTex.getSize().y;

	scaleX = widthCircle / widthSquare;
	scaleY = heightCircle / heightSquare;

	_currentSpr->setScale(scaleX, scaleY);

	RenderWindow window(VideoMode(800, 800, 32), "Splats");

	while (window.isOpen())
	{
		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					_currentSpr->move(0, -movementPos);
				}
				if (Keyboard::isKeyPressed(Keyboard::A))
				{
					_currentSpr->move(-movementPos, 0);
				}
				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					_currentSpr->move(0, movementPos);
				}
				if (Keyboard::isKeyPressed(Keyboard::D))
				{
					_currentSpr->move(movementPos, 0);
				}
				if (Keyboard::isKeyPressed(Keyboard::Space) && isSquare == true)
				{
					_currentSpr->setTexture(_rcircleTex);
					_currentSpr->setScale(1, 1);
					isSquare = false;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Space) && isSquare == false)
				{
					_currentSpr->setTexture(_ysquareTex);
					_currentSpr->setScale(scaleX, scaleY);
					isSquare = true;
				}
			}
		}
		window.clear();
		window.draw(*_currentSpr);
		window.display();
	}
}
