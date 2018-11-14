#include <iostream>
#include <SFML/Graphics.hpp>

#include "Snowflake.h"

////////////////////////////////////////////////////////////
/// \brief Возвращает массив точек кривой Безье для 3 контрольных точек
///
/// \param p1, p2, p3  Соответственно 1, 2, 3 контрольные точки   
/// \param count	   Количество точек из которых будет состоять кривая
////////////////////////////////////////////////////////////

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);

	snow::Snowflake f1;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		f1.draw(window);
		window.display();
	}

	return 0;
}
