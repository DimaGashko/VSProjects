#pragma once

#include <SFML/Graphics.hpp>
#include "Snowstorm.h"

namespace snow {

	class SnowstormDemo {
	public:
		SnowstormDemo();
		void initWindow();
		void start();
		void init();
		void update();
		~SnowstormDemo() {};
	private:
		sf::RenderWindow _window;
		snow::Snowstorm _snowstorm;
	};

} // namespace snow
