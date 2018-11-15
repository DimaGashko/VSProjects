#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Figure.h"

namespace snow {

	class Snowflake {
	public:
		Snowflake();
		void draw(sf::RenderWindow &window);
		~Snowflake() {};
	private:
		Figure _figure;
	};

} // namespace snow

