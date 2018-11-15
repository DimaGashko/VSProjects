#include "SnowStorm.h"

namespace snow {

	Snowstorm::Snowstorm() {
		initWindow();
	}

	void Snowstorm::initWindow() {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		_window.create(sf::VideoMode(1000, 600), "Snowstorm", sf::Style::Default, settings);
	}

	void Snowstorm::start() {
		while (_window.isOpen()) {
			sf::Event event;
			while (_window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					_window.close();
				}
				else if (event.type == sf::Event::Resized) {
					sf::FloatRect visible(0, 0, float(event.size.width), float(event.size.height));
					_window.setView(sf::View(visible));
				}
			}

			_window.clear();
			
			_window.display();
		}

	}

} // namespace snow
