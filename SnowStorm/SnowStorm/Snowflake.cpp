#include <SFML/Graphics.hpp>
#include <cmath>

#include "Snowflake.h"

namespace snow {
	Snowflake::Snowflake(): 
		_coords(sf::Vector2f(200, 200)),
		_angle(0),
		_size(30)
	{
		
	}

	void Snowflake::updateConfig() {
		double const PI = 3.14159265358979323846;

		_p1.x = _coords.x + _size * cos(_angle + PI / 2) * 8 / 3;
		_p1.y = _coords.y + _size * sin(_angle + PI / 2) * 8 / 3;

		_p2.x = _coords.x + _b * _size * cos(_angle + _angleB1);
		_p2.y = _coords.y + _b * _size * sin(_angle + _angleB1);

		_p3.x = _coords.x + 2 * _size * cos(_angle + PI / 2);
		_p3.y = _coords.y + 2 * _size * sin(_angle + PI / 2);

		_p4.x = _coords.x + 2 * _size * cos(_angle + PI / 4);
		_p4.y = _coords.y + 2 * _size * sin(_angle + PI / 4);

		_p5.x = _coords.x + 2 * _size * cos(_angle);
		_p5.y = _coords.y + 2 * _size * sin(_angle);

		_p6.x = _coords.x + _b * _size * cos(_angle + _angleB2);
		_p6.y = _coords.y + _b * _size * sin(_angle + _angleB2);

		_p7.x = _coords.x + _size * cos(_angle) * 8 / 3;
		_p7.y = _coords.y + _size * sin(_angle) * 8 / 3;
	}

	void Snowflake::draw(sf::RenderWindow &window) {
		updateConfig();

		sf::Vertex part1[] = {_p1, _p2, _p3, _coords, _p5, _p6, _p7};
		sf::Vertex part2[] = { _coords, _p4};

		window.draw(part1, 7, sf::LineStrip);
		window.draw(part2, 2, sf::Lines);
	}

	const double Snowflake::_angleB1 = atan(7);
	const double Snowflake::_angleB2 = atan(1 / 7);
	const double Snowflake::_b = 1 / 3 * sqrt(50);

} // namespace snow