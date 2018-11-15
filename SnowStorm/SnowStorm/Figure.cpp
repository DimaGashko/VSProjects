#include <SFML/Graphics.hpp>
#include <cmath>

#include "Figure.h"

namespace snow {
	const double PI = 3.14159265358979323846;

	////////////////////////////////////////////////////////////
	/// \brief ���������� ������ ����� ������ ����� ��� 3 ����������� �����
	///
	/// \param p1, p2, p3  �������������� 1, 2, 3 ����������� �����   
	/// \param count	   ���������� ����� �� ������� ����� �������� ������
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

	void Figure::draw(sf::RenderWindow &window) {
		const float angle = float(PI / 2);
		const float startAngle = _angle;

		for (int i = 0; i < 4; i++) {
			drawFragment(window);
			rotate(angle);
		}

		setAngle(startAngle);
	}

	void Figure::drawFragment(sf::RenderWindow &window) {
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

	void Figure::updatePoints() {
		p1.x = float(_coords.x + _size * cos(_angle + PI / 2) * 8 / 3);
		p1.y = float(_coords.y + _size * sin(_angle + PI / 2) * 8 / 3);
		
		p2.x = float(_coords.x + _P0P2 * _size * cos(_angle + _BETA1));
		p2.y = float(_coords.y + _P0P2 * _size * sin(_angle + _BETA1));
		
		p3.x = float(_coords.x + 2 * _size * cos(_angle + PI / 2)),
		p3.y = float(_coords.y + 2 * _size * sin(_angle + PI / 2));

		p4.x = float(_coords.x + 2 * _size * cos(_angle + PI / 4));
		p4.y = float(_coords.y + 2 * _size * sin(_angle + PI / 4));

		p5.x = float(_coords.x + 2 * _size * cos(_angle));
		p5.y = float(_coords.y + 2 * _size * sin(_angle));
		
		p6.x = float(_coords.x + _P0P2 * _size * cos(_angle + _BETA2));
		p6.y = float(_coords.y + _P0P2 * _size * sin(_angle + _BETA2));

		p7.x = float(_coords.x + _size * cos(_angle) * 8 / 3);
		p7.y = float(_coords.y + _size * sin(_angle) * 8 / 3);

		p8.x = float(_coords.x + _P0P8 * _size * cos(_angle + PI / 2));
		p8.y = float(_coords.y + _P0P8 * _size * sin(_angle + PI / 2));

		p9.x = float(_coords.x + _P0P8 * _size * cos(_angle));
		p9.y = float(_coords.y + _P0P8 * _size * sin(_angle));
	}

	void Figure::setPosition(sf::Vector2f coords) {
		_coords.x = coords.x;
		_coords.y = coords.y;

		updatePoints();
	}

	sf::Vector2f Figure::getPosition() {
		return sf::Vector2f(_coords);
	}

	void Figure::move(sf::Vector2f offset) {
		setPosition(_coords + offset);
	}

	void Figure::setAngle(float angle) {
		_angle = angle;
		updatePoints();
	}

	float Figure::getAngle() {
		return _angle;
	}

	void Figure::rotate(float angle) {
		setAngle(_angle + angle);
	}

	void Figure::setSize(float size) {
		if (size < 1) return;
		_size = size;

		updatePoints();
	}

	float Figure::getSize() {
		return _size;
	}

	const double Figure::_BETA1 = atan(7);
	const double Figure::_BETA2 = PI / 2 - Figure::_BETA1;
	const double Figure::_P0P2 = 1.f / 3.f * sqrt(50);
	const double Figure::_P0P8 = sqrt(2);

} // namespace snow
