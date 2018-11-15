#include <iostream>
#include <SFML/Graphics.hpp>

#include "Figure.h"

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);

	snow::Figure f1(sf::Vector2f(400, 400), 50, 0.3f);
	snow::Figure f2(sf::Vector2f(200, 100), 20, 1.6f);
	snow::Figure f3(sf::Vector2f(500, 100), 30, 0.6f);
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visible(0, 0, float(event.size.width), float(event.size.height));
				window.setView(sf::View(visible));
			}
		}

		window.clear();
		f1.draw(window);
		f2.draw(window);
		f3.draw(window);
		window.display();
	}

	return 0;
}
