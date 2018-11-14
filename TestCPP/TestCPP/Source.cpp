#include <iostream>
#include <SFML/Graphics.hpp>

#include "Point.h"
#include "Line.h"

////////////////////////////////////////////////////////////
/// \brief Возвращает массив точек кривой Безье для 3 контрольный точек
///
/// \param p1, p2, p3  Соответственно 1, 2, 3 контрольные точки   
/// \param count	   Количество точек из которых будет состоять кривая
///
////////////////////////////////////////////////////////////
sf::VertexArray getBezierCoords(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, int count = 3);

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);
	
	sf::Vector2f p1(50, 50);
	sf::Vector2f p2(500, 50);
	sf::Vector2f p3(500, 500);

	auto test = getBezierCoords(p1, p2, p3, 5);

	sf::CircleShape c1(3), c2(3), c3(3);
	c1.move(p1);
	c2.move(p2);
	c3.move(p3);

	c1.setFillColor(sf::Color(255, 0, 0));
	c2.setFillColor(sf::Color(0, 255, 0));
	c3.setFillColor(sf::Color(0, 0, 255));

	while (window.isOpen())	{
		sf::Event event;
		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(test);
		window.draw(c1);
		window.draw(c2);
		window.draw(c3);
		window.display();
	}
	
	return 0;
}

sf::VertexArray getBezierCoords(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, int count) {
	if (count < 3) count = 3;

	sf::VertexArray vertices(sf::LineStrip, count);

	for (int i = 0; i < count; i++) {
		float t = float(i) / (count - 1);

		vertices[i].position = ((1.f - t) * (1.f - t)) * p1
			+ (2.f * (1.f - t) * t) * p2
			+ (t * t) * p3;
	}

	return vertices;
}