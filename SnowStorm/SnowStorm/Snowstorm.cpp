#include <SFML/Graphics.hpp>
#include "Snowstorm.h"

namespace snow {

	Snowstorm::Snowstorm() {

	}

	void Snowstorm::draw(sf::RenderWindow &window) {		
		for (std::shared_ptr<Snowflake> item : _snowflakes) {
			item->draw(window);
		}
	}

	void Snowstorm::addSnowflake(std::shared_ptr<Snowflake> snowflake) {
		_snowflakes.push_back(snowflake);
	}

} // namespace snow