#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

void events(), fpsTest();

int main() {
	//events();
	fpsTest();

	return 0;
}

void events() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(100);
	shape.setFillColor(sf::Color(255, 255, 0));
	
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			} 
			else if (event.type == sf::Event::KeyPressed) {
				
				cout << "Pressed (" << event.key.code << ") ";
			}
			else if (event.type == sf::Event::KeyReleased) {
				cout << endl << "Released" << endl;
			}

		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

void fpsTest() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(100);
	shape.setFillColor(sf::Color(255, 255, 0));

	sf::Clock clock;
	float lastTime = 0;
	int fps = 0;

	while (window.isOpen()) {
		sf::Event event;
		
		cout << clock.restart().asMicroseconds() << endl;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

