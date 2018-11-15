#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Snowflake.h"

namespace snow {

	class Snowstorm {
	public:
		Snowstorm();
		void addSnowflake(Snowflake* snowflake);
		//void update();
		void draw(sf::RenderWindow &window);
		~Snowstorm() {};
	private: 
		std::vector<Snowflake*> _snowflakes;
	};

} // namespace snow

