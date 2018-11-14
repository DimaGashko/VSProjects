#include <SFML/Graphics.hpp>
#include <cmath>

#include "Snowflake.h"

namespace snow {
	const double PI = 3.14159265358979323846;

	////////////////////////////////////////////////////////////
	/// \brief Возвращает массив точек кривой Безье для 3 контрольных точек
	///
	/// \param p1, p2, p3  Соответственно 1, 2, 3 контрольные точки   
	/// \param count	   Количество точек из которых будет состоять кривая
	////////////////////////////////////////////////////////////
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

	Snowflake::Snowflake(): 
		_coords(sf::Vector2f(200, 200)),
		_angle(0.3),
		_size(50)
	{
		
	}

	void Snowflake::drawFragment(sf::RenderWindow &window, float fragmentAngle) {
		float angle = _angle + fragmentAngle;

		sf::Vector2f p1(
			_coords.x + _size * cos(angle + PI / 2) * 8 / 3,
			_coords.y + _size * sin(angle + PI / 2) * 8 / 3
		);
		sf::Vector2f p2(
			_coords.x + _D02 * _size * cos(angle + _BETA1),
			_coords.y + _D02 * _size * sin(angle + _BETA1)
		);
		sf::Vector2f p3(
			_coords.x + 2 * _size * cos(angle + PI / 2),
			_coords.y + 2 * _size * sin(angle + PI / 2)
		);
		sf::Vector2f p4(
			_coords.x + 2 * _size * cos(angle + PI / 4),
			_coords.y + 2 * _size * sin(angle + PI / 4)
		);
		sf::Vector2f p5(
			_coords.x + 2 * _size * cos(angle),
			_coords.y + 2 * _size * sin(angle)
		);
		sf::Vector2f p6(
			_coords.x + _D02 * _size * cos(angle + _BETA2),
			_coords.y + _D02 * _size * sin(angle + _BETA2)
		);
		sf::Vector2f p7(
			_coords.x + _size * cos(angle) * 8 / 3,
			_coords.y + _size * sin(angle) * 8 / 3
		);
		sf::Vector2f p8(
			_coords.x + _D08 * _size * cos(angle + PI / 2),
			_coords.y + _D08 * _size * sin(angle + PI / 2)
		);
		sf::Vector2f p9(
			_coords.x + _D08 * _size * cos(angle),
			_coords.y + _D08 * _size * sin(angle)
		);

		sf::Vertex part1[] = { p1, p2, p3, _coords };
		sf::Vertex part2[] = { _coords, p4 };
		sf::Vertex part3[] = { p5, p6, p7 };

		auto arc1 = getBezierCoords(_coords, p8, p4, 10);
		auto arc2 = getBezierCoords(_coords, p9, p4, 10);

		window.draw(part1, 4, sf::LineStrip);
		window.draw(part2, 2, sf::Lines);
		window.draw(part3, 3, sf::LineStrip);
		window.draw(arc1);
		window.draw(arc2);
	}

	void Snowflake::draw(sf::RenderWindow &window) {
		drawFragment(window, 0);
		drawFragment(window, PI / 2);
		drawFragment(window, PI);
		drawFragment(window, -PI / 2);
		
	}

	const double Snowflake::_BETA1 = atan(7);
	const double Snowflake::_BETA2 = PI / 2 - Snowflake::_BETA1;
	const double Snowflake::_D02 = 1.f / 3.f * sqrt(50);
	const double Snowflake::_D08 = sqrt(2);

} // namespace snow

