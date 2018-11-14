#include <iostream>
#include <SFML/Graphics.hpp>

#include "Snowflake.h"

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);

	snow::Snowflake f1;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visible(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visible));
			}
		}

		window.clear();
		f1.draw(window);
		window.display();
	}

	return 0;
}
