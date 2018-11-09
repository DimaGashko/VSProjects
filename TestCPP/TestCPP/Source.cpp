#include <iostream>
#include <SFML/Graphics.hpp>

#include "Point.h"
#include "Line.h"

using namespace std;

int main() {
	Line l1(0, 0, 5, 5);
	Line l2(-5, -5, 10, 10);

	l1.show();
	l2.show();

	cout << "- - - - -" << endl;

	l1.move(10, 10);
	l2.move(20, 20);

	l1.show();
	l2.show(); 

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())	{
		sf::Event event;
		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	
	return 0;
}