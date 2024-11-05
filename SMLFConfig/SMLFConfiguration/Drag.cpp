#include "Drag.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;


Drag::Drag()
{
	Texture _rcircleTex;
	Sprite _rcircleUpLeft;
	Sprite _rcircleUpRight;
	Sprite _rcircleDownLeft;
	Sprite _rcircleDownRight;

	Texture _cursorTex;
	Sprite _cursorSpr;
	Sprite* _currentSelectedSprite = nullptr;

	Event evt;
	Mouse mouse;
	Vector2i spritePosition = mouse.getPosition();
	Vector2i spriteLastPosition = mouse.getPosition();


	_rcircleTex.loadFromFile("rcircle.png");
	_rcircleUpLeft.setTexture(_rcircleTex);
	_rcircleUpRight.setTexture(_rcircleTex);
	_rcircleDownLeft.setTexture(_rcircleTex);
	_rcircleDownRight.setTexture(_rcircleTex);

	_rcircleUpLeft.setPosition(0, 0);
	_rcircleUpRight.setPosition(672, 0);
	_rcircleDownRight.setPosition(0, 472);
	_rcircleDownLeft.setPosition(672, 472);

	RenderWindow window(VideoMode(800, 600, 32), "Drag");

	while (window.isOpen())
	{
		Vector2i mousePositionInt = mouse.getPosition(window);
		Vector2f mousePosition = window.mapPixelToCoords(mousePositionInt);



		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				if (mouse.isButtonPressed(mouse.Left))
				{
					if (_rcircleUpLeft.getGlobalBounds().contains(mousePosition))
					{
						_currentSelectedSprite = &_rcircleUpLeft;
					}
					else if (_rcircleDownLeft.getGlobalBounds().contains(mousePosition))
					{
						_currentSelectedSprite = &_rcircleDownLeft;
					}
					else if (_rcircleUpRight.getGlobalBounds().contains(mousePosition))
					{
						_currentSelectedSprite = &_rcircleUpRight;
					}
					else if (_rcircleDownRight.getGlobalBounds().contains(mousePosition))
					{
						_currentSelectedSprite = &_rcircleDownRight;
					}
				}
				break;
			case Event::MouseButtonReleased:
				_currentSelectedSprite = nullptr;
				break;
			case Event::MouseMoved:
				if (_currentSelectedSprite != nullptr)
				{
					_currentSelectedSprite->setPosition(mousePosition.x, mousePosition.y);
				}
				break;
			}
		}

		window.clear();
		window.draw(_cursorSpr);
		window.draw(_rcircleUpLeft);
		window.draw(_rcircleUpRight);
		window.draw(_rcircleDownRight);
		window.draw(_rcircleDownLeft);
		window.display();
	}
}
