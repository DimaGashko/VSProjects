#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

void events(), fpsTest(), sprites();

int main() {
	//events();
	//fpsTest();
	sprites();

	system("pause");
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

			else if (event.type == sf::Event::Resized) {
				cout << endl << "Resized " << endl;
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


void sprites() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	
	sf::Texture texture;
	if (!texture.loadFromFile("img/sprite.png", sf::IntRect(16,16,16,16))) {
		cout << "Cannot load" << endl;
	}

	sf::Sprite sprite(texture);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}