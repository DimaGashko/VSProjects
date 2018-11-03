#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

void events(), fpsTest(), sprites(), views(), sounds(), recording(), preventResizing();

int main() {
	preventResizing();

	//system("pause");
	return 0;
}

void preventResizing() {
	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML works!", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(350);

	sf::Texture texture;
	if (!texture.loadFromFile("img/beach.jpg")) {
		cout << "Cannot load" << endl;
	}

	sf::Sprite sprite(texture);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visible(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visible));
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}

void recording() {
	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML works!");
	window.setFramerateLimit(350);

	if (!sf::SoundBufferRecorder::isAvailable()) {
		cout << "Recording not supported" << endl;
	}

	sf::Texture texture;
	if (!texture.loadFromFile("img/beach.jpg")) {
		cout << "Cannot load" << endl;
	}

	sf::Sprite sprite(texture);

	sf::SoundBufferRecorder recorder;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visible(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visible));
			}
			else if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::R) {
					cout << "Recording..." << endl;
					recorder.start();
				}
				else if (event.key.code == sf::Keyboard::P) {
					cout << "Your record saved";
					recorder.stop();
					cout << "Playing" << endl;
					buffer = recorder.getBuffer();
					sound.setBuffer(buffer);
					sound.play();
				}
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}

void sounds() {
	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML works!");
	window.setFramerateLimit(350);

	sf::Music music;
	if (!music.openFromFile("sounds/maker.ogg")) {
		cout << "Cannot load" << endl;
	}

	music.play();

	sf::Texture texture;
	if (!texture.loadFromFile("img/beach.jpg")) {
		cout << "Cannot load" << endl;
	}

	sf::Sprite sprite(texture);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visible(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visible));
			}
			else if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::P) {
					music.play();
				} 
				else if (event.key.code == sf::Keyboard::S) {
					music.pause();
				}
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}

void views() {
	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML works!");
	window.setFramerateLimit(350);

	sf::Texture texture;
	if (!texture.loadFromFile("img/beach.jpg")) {
		cout << "Cannot load" << endl;
	}

	sf::Sprite sprite(texture);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visible(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visible));
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
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
	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML works!");
	
	sf::Texture texture;
	if (!texture.loadFromFile("img/sprite.png")) {
		cout << "Cannot load" << endl;
	}

	double r = 255;
	double g = 255;
	double b = 255;

	sf::Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect(16, 16, 160, 320));
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}
		if (r < 0) r = 255;
		if (g > 255) g = 0;
		if (b > 255) b = 0;

		r -= 0.1;
		g += 0.2;
		b += 0.3;

		sprite.setColor(sf::Color(r, g, b));

		window.clear();
		window.draw(sprite);
		window.display();
	}
}