#include <SFML/Graphics.hpp>
#include "Snowflake.h"

namespace snow {

	Snowflake::Snowflake() {

	}

	void Snowflake::draw(sf::RenderWindow &window) {
		_figure->draw(window);
	}

} // namespace snow

