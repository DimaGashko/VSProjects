#pragma once

#include <SFML/Graphics.hpp>
#include "Figure.h"

namespace snow {

	class Snowflake {
	public:
		Snowflake();
		void draw(sf::RenderWindow &window);
		~Snowflake() {};
		Figure _figure;
	private:
		
	};

} // namespace snow

