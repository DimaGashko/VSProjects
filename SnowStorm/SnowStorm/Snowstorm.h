#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace snow {

	class Snowstorm {
	public:
		Snowstorm();
		void initWindow();
		void start();
		~Snowstorm() {};
	private:
		sf::RenderWindow _window;
	};

} // namespace snow
