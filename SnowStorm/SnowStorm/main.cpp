#include <iostream>
#include <SFML/Graphics.hpp>

#include "Figure.h"

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);
	window.setFramerateLimit(10);

	snow::Figure f1(sf::Vector2f(250, 250), 50, 0.f);
	snow::Figure f2(sf::Vector2f(50, 250), 20, 0.f);
	snow::Figure f3(sf::Vector2f(600, 350), 20, 0.f);

	float step = 5;
	
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
			else if (event.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					f1.rotate(0.1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					f1.rotate(-0.1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					f1.move(sf::Vector2f(0, -step));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					f1.move(sf::Vector2f(0, step));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					f1.move(sf::Vector2f(-step, 0));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					f1.move(sf::Vector2f(step, 0));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					f1.setSize(f1.getSize() + 1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					f1.setSize(f1.getSize() - 1);
				}
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
