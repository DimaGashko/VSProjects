#include <SFML/Graphics.hpp>
#include "Snowstorm.h"

namespace snow {

	Snowstorm::Snowstorm() {

	}

	void Snowstorm::draw(sf::RenderWindow &window) {		
		for (Snowflake *item : _snowflakes) {
			item->draw(window);
		}
	}

	void Snowstorm::addSnowflake(Snowflake *snowflake) {
		_snowflakes.push_back(snowflake);
	}

} // namespace snow