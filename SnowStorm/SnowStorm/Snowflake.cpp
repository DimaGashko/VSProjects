#include <SFML/Graphics.hpp>
#include <cmath>

#include "Snowflake.h"

sf::VertexArray getBezierCoords(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, int count = 30) {
	if (count < 3) count = 3;

	sf::VertexArray vertices(sf::LineStrip, count);

	for (int i = 0; i < count; i++) {
		float t = float(i) / (count - 1);

		vertices[i].position = ((1.f - t) * (1.f - t)) * p1
			+ (2.f * (1.f - t) * t) * p2
			+ (t * t) * p3;
	}

	return vertices;
}

namespace snow {
	Snowflake::Snowflake(): 
		_coords(sf::Vector2f(200, 200)),
		_angle(0),
		_size(50)
	{
		
	}

	void Snowflake::updateConfig(float a) {
		double const PI = 3.14159265358979323846;
		float angle = _angle + a;

		_p1.x = _coords.x + _size * cos(angle + PI / 2) * 8 / 3;
		_p1.y = _coords.y + _size * sin(angle + PI / 2) * 8 / 3;

		_p2.x = _coords.x + _d02 * _size * cos(angle + _angleB1);
		_p2.y = _coords.y + _d02 * _size * sin(angle + _angleB1);

		_p3.x = _coords.x + 2 * _size * cos(angle + PI / 2);
		_p3.y = _coords.y + 2 * _size * sin(angle + PI / 2);

		_p4.x = _coords.x + 2 * _size * cos(angle + PI / 4);
		_p4.y = _coords.y + 2 * _size * sin(angle + PI / 4);

		_p5.x = _coords.x + 2 * _size * cos(angle);
		_p5.y = _coords.y + 2 * _size * sin(angle);

		_p6.x = _coords.x + _d02 * _size * cos(angle + _angleB2);
		_p6.y = _coords.y + _d02 * _size * sin(angle + _angleB2);

		_p7.x = _coords.x + _size * cos(angle) * 8 / 3;
		_p7.y = _coords.y + _size * sin(angle) * 8 / 3;

		_p8.x = _coords.x + _d08 * _size * cos(angle + PI / 2);
		_p8.y = _coords.y + _d08 * _size * sin(angle + PI / 2);

		_p9.x = _coords.x + _d08 * _size * cos(angle);
		_p9.y = _coords.y + _d08 * _size * sin(angle);
	}

	void Snowflake::draw(sf::RenderWindow &window) {
		updateConfig(0);

		sf::Vertex part1[] = {_p1, _p2, _p3, _coords};
		sf::Vertex part2[] = {_coords, _p4};
		sf::Vertex part3[] = {_p5, _p6, _p7};

		auto arc1 = getBezierCoords(_coords, _p8, _p4);
		auto arc2 = getBezierCoords(_coords, _p9, _p4);

		window.draw(part1, 4, sf::LineStrip);
		window.draw(part2, 2, sf::Lines);
		window.draw(part3, 3, sf::LineStrip);
		window.draw(arc1);
		window.draw(arc2);
	}

	const double Snowflake::_angleB1 = atan(7);
	const double Snowflake::_angleB2 = atan(1.f / 7.f);
	const double Snowflake::_d02 = 1.f / 3.f * sqrt(50);
	const double Snowflake::_d08 = sqrt(2);

} // namespace snow