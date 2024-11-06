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
	Sprite* _ysquareSpr = new Sprite();
	Sprite* _rcircleSpr = new Sprite();

	_ysquareTex.loadFromFile("cuad_yellow.png");
	_rcircleTex.loadFromFile("rcircle.png");
	_ysquareSpr->setTexture(_ysquareTex);
	_rcircleSpr->setTexture(_rcircleTex);

	RenderWindow window(VideoMode(800, 600, 32), "Splats");

	while (window.isOpen())
	{
		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case Event::Closed:
				window.close();
				break;
			}
		}
	}
}
