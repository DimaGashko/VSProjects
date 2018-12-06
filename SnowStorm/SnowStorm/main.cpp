#include <SFML/Graphics.hpp>
#include <cmath>
#include "Figure.h" 

void manipulate(figure::Figure &f, sf::RenderWindow &window);

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Figure", sf::Style::Default, settings);
	window.setFramerateLimit(120);

	sf::Vector2f center(400.0f, 400.0f);
	figure::Figure f(0.f, 200.f, center);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		f.draw(window);

		manipulate(f, window);

		window.display();
	}

	return 0;
}

void manipulate(figure::Figure &f, sf::RenderWindow &window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		f.rotate(-0.1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		f.rotate(0.1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		f.scale(1.001);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		f.scale(0.999);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		f.move(0.0, -10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		f.move(0.0, 10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		f.move(-10, 0.0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		f.move(10, 0.0);
	}
}