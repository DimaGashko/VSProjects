#include <iostream>
#include <SFML/Graphics.hpp>

#include "Point.h"
#include "Line.h"

using namespace std;

////////////////////////////////////////////////////////////
/// \brief Возвращает массив точек кривой Безье для 3 контрольный точек
///
/// \param p1, p2, p3  Соответственно 1, 2, 3 контрольные точки   
/// \param count	   Количество точек из которых будет состоять кривая
///
////////////////////////////////////////////////////////////
sf::VertexArray getBezierCoords(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, int count) {
	sf::VertexArray vertices(sf::LineStrip, count);

	for (int i = 0; i < count; i++) {
		float t = (float)i / count;

		vertices[i].position = (1.f - t) * (1.f - t) * p1
			+ 2.f * (1.f - t) * p2
			+ t * t * p3;
	}

	return vertices;
}

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);

	auto test = getBezierCoords(
		sf::Vector2f(50, 50),
		sf::Vector2f(300, 50),
		sf::Vector2f(300, 300),
		50
	);

	while (window.isOpen())	{
		sf::Event event;
		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(test);
		window.display();
	}
	
	return 0;
}