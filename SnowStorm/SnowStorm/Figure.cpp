#include <SFML/Graphics.hpp>
#include <cmath>

#include "Figure.h"

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

	Figure::Figure(): 
		_coords(sf::Vector2f(0, 0)),
		_size(20),
		_angle(0)
	{
		
	}

	Figure::Figure(sf::Vector2f coords, float size, float angle) :
		_coords(coords),
		_size(size),
		_angle(angle)
	{

	}

	void Figure::drawFragment(sf::RenderWindow &window, float fragmentAngle) {
		float angle = _angle + fragmentAngle;

		sf::Vector2f p1(
			float(_coords.x + _size * cos(angle + PI / 2) * 8 / 3),
			float(_coords.y + _size * sin(angle + PI / 2) * 8 / 3)
		);
		sf::Vector2f p2(
			float(_coords.x + _P0P2 * _size * cos(angle + _BETA1)),
			float(_coords.y + _P0P2 * _size * sin(angle + _BETA1))
		);
		sf::Vector2f p3(
			float(_coords.x + 2 * _size * cos(angle + PI / 2)),
			float(_coords.y + 2 * _size * sin(angle + PI / 2))
		);
		sf::Vector2f p4(
			float(_coords.x + 2 * _size * cos(angle + PI / 4)),
			float(_coords.y + 2 * _size * sin(angle + PI / 4))
		);
		sf::Vector2f p5(
			float(_coords.x + 2 * _size * cos(angle)),
			float(_coords.y + 2 * _size * sin(angle))
		);
		sf::Vector2f p6(
			float(_coords.x + _P0P2 * _size * cos(angle + _BETA2)),
			float(_coords.y + _P0P2 * _size * sin(angle + _BETA2))
		);
		sf::Vector2f p7(
			float(_coords.x + _size * cos(angle) * 8 / 3),
			float(_coords.y + _size * sin(angle) * 8 / 3)
		);
		sf::Vector2f p8(
			float(_coords.x + _P0P8 * _size * cos(angle + PI / 2)),
			float(_coords.y + _P0P8 * _size * sin(angle + PI / 2))
		);
		sf::Vector2f p9(
			float(_coords.x + _P0P8 * _size * cos(angle)),
			float(_coords.y + _P0P8 * _size * sin(angle))
		);

		sf::Vertex part1[] = { p1, p2, p3, _coords };
		sf::Vertex part2[] = { _coords, p4 };
		sf::Vertex part3[] = { p5, p6, p7 };

		auto arc1 = getBezierCoords(_coords, p8, p4, 15);
		auto arc2 = getBezierCoords(_coords, p9, p4, 15);

		window.draw(part1, 4, sf::LineStrip);
		window.draw(part2, 2, sf::Lines);
		window.draw(part3, 3, sf::LineStrip);
		window.draw(arc1);
		window.draw(arc2);
	}

	void Figure::draw(sf::RenderWindow &window) {
		drawFragment(window, 0);
		drawFragment(window, float(PI / 2));
		drawFragment(window, float(PI));
		drawFragment(window, float(-PI / 2));
		
	}

	void Figure::setPosition(sf::Vector2f coords) {
		_coords.x = coords.x;
		_coords.y = coords.y;
	}

	sf::Vector2f Figure::getPosition() {
		return sf::Vector2f(_coords);
	}

	void Figure::move(sf::Vector2f offset) {
		_coords.x += offset.x;
		_coords.y += offset.y;
	}

	void Figure::setAngle(float angle) {
		_angle = angle;
	}

	float Figure::getAngle() {
		return _angle;
	}

	void Figure::rotate(float angle)	{
		_angle += angle;
	}

	const double Figure::_BETA1 = atan(7);
	const double Figure::_BETA2 = PI / 2 - Figure::_BETA1;
	const double Figure::_P0P2 = 1.f / 3.f * sqrt(50);
	const double Figure::_P0P8 = sqrt(2);

} // namespace snow

