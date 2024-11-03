// SMLFConfiguration.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Texture _circuloAzul;
Sprite _spriteCirculoAzul;
Sprite _cursor;
Texture mat_cursor;
Event evt;

int main()
{
	mat_cursor.loadFromFile("D:/Max/FACU/Materias/Modelos y Algoritmos para Videojuegos I/Unidad3_Assets/bcircle.png");
	_cursor.setTexture(mat_cursor);
	_cursor.setPosition(0, 0);
	_cursor.setScale(0.2, 0.2);

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Transparencias");

	App.setMouseCursorVisible(false);
	while (App.isOpen())
	{
		while (App.pollEvent(evt))
		{
			switch (evt.type)
			{
			case Event::Closed:
				App.close();
				break;
				/*
			case Event::MouseMoved:
				_cursor.setPosition(evt.mouseMove.x, evt.mouseMove.y);
				break;
				*/
			}
			Vector2i windowPosition = Mouse.setPosition(windowPosition.x, windowPosition.y);
		}
		App.clear(Color::White);
		App.draw(_cursor);
		App.display();
	}

	return 0;
}
























// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
