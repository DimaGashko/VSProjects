#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Snowflake.h"

namespace snow {

	class Snowstorm {
	public:
		Snowstorm();
		void addSnowflake(std::shared_ptr<Snowflake> snowflake);
		//void update();
		void draw(sf::RenderWindow &window);
		~Snowstorm() {};
	private: 
		std::vector<std::shared_ptr<Snowflake>> _snowflakes;
	};

} // namespace snow

