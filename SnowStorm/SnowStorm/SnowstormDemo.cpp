#include "SnowstormDemo.h"

namespace snow {

	SnowstormDemo::SnowstormDemo() {
		initWindow();
		init();
	}

	void SnowstormDemo::initWindow() {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		_window.create(sf::VideoMode(1000, 600), "Snowstorm", sf::Style::Default, settings);
	}

	void SnowstormDemo::start() {
		snow::Figure f1(sf::Vector2f(650,300),100,0.4f);
		snow::Figure f2(sf::Vector2f(250, 200), 80, 1.1f);
		snow::Figure f3(sf::Vector2f(400, 500), 40, -0.2f);

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
			f1.draw(_window);
			f2.draw(_window);
			f3.draw(_window);
			update();
			_window.display();
		}

	}

	void SnowstormDemo::init() {
		Snowflake *a = new Snowflake();
		_snowstorm.addSnowflake(a);
	}

	void SnowstormDemo::update() {
		_snowstorm.draw(_window);
	}

} // namespace snow
