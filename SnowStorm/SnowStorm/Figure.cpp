#include <SFML\Graphics.hpp>
#include <cmath>
#include "Figure.h"

const double pi = 3.14159265358979323846;

namespace figure {
	Figure::Figure() {
		_angle = 0;
		_radius = 300;
		_center.x = 200.0;
		_center.y = 200.0;
	}

	Figure::Figure(float angle, float radius, sf::Vector2f center) {
		_angle = angle;
		_radius = radius;
		_center = center;

	}

	sf::Vector2f Figure::getCenter() {
		return _center;
	}

	void Figure::setCenter(sf::Vector2f v) {
		_center = v;
	}


	void Figure::setRadius(float radius) {
		_radius = radius;
	}

	float Figure::getRadius() {
		return _radius;
	}

	void Figure::setAngle(float angle) {
		_angle = angle;
	}

	float Figure::getAngle() {
		return _angle;
	}

	void Figure::rotate(float angle) {
		setAngle(_angle + angle);
	}

	void Figure::scale(float coeficient) {
		setRadius(_radius * coeficient);
	}

	void Figure::move(float x, float y) {
		_center.x += x;
		_center.y += y;
	}

	void Figure::_setPoints() {

		_p1.x = float(_center.x + _radius / 2 * cos(_angle));
		_p1.y = float(_center.y + _radius / 2 * sin(_angle));

		_p2.x = float(_center.x + _radius / 2 * cos(_angle + _sigma));
		_p2.y = float(_center.y + _radius / 2 * sin(_angle + _sigma));

		_p3.x = float(_center.x + _radius / 2 * cos(pi / 2 + _angle - _sigma));
		_p3.y = float(_center.y + _radius / 2 * sin(pi / 2 + _angle - _sigma));

		_p4.x = float(_center.x + _radius / 2 * cos(_angle + pi / 2));
		_p4.y = float(_center.y + _radius / 2 * sin(_angle + pi / 2));

		_p5.x = float(_center.x + _radius * cos(_angle));
		_p5.y = float(_center.y + _radius * sin(_angle));

		_p6.x = float(_center.x + _radius * 1.5 * cos(_angle));
		_p6.y = float(_center.y + _radius * 1.5 * sin(_angle));

		_p7.x = float(_center.x + _radius * _a * cos(_angle + _alpha));
		_p7.y = float(_center.y + _radius * _a * sin(_angle + _alpha));

		_p8.x = float(_center.x + _radius * cos(_angle + _sigma));
		_p8.y = float(_center.y + _radius * sin(_angle + _sigma));

		_p9.x = float(_center.x + _radius * cos(pi / 2 + _angle - _sigma));
		_p9.y = float(_center.y + _radius * sin(pi / 2 + _angle - _sigma));

		_p10.x = float(_center.x + _radius * _a * cos(_angle + pi / 2 - _alpha));
		_p10.y = float(_center.y + _radius * _a * sin(_angle + pi / 2 - _alpha));

		_p11.x = float(_center.x + _radius * 1.5 * cos(_angle + pi / 2));
		_p11.y = float(_center.y + _radius * 1.5 * sin(_angle + pi / 2));

		_p12.x = float(_center.x + _radius * cos(_angle + pi / 2));
		_p12.y = float(_center.y + _radius * sin(_angle + pi / 2));

		_p13.x = float(_center.x + _radius * 3 / 4 * cos(_angle + pi / 4));
		_p13.y = float(_center.y + _radius * 3 / 4 * sin(_angle + pi / 4));

	}

	void Figure::_drawPart(sf::RenderWindow &window) {

		sf::Vertex part1[] = { _p4, _p3, _p2, _p1 };
		sf::Vertex part2[] = { _p5, _p7, _p6 };
		sf::Vertex part3[] = { _p12, _p10, _p11 };
		sf::Vertex part4[] = { _center, _p13 };
		sf::Vertex part5[] = { _center, _p5 };

		auto arc1 = _getBezier(_p8, _p13, _p9, 50);

		window.draw(part1, 4, sf::LineStrip);
		window.draw(part2, 3, sf::LineStrip);
		window.draw(part3, 3, sf::LineStrip);
		window.draw(part4, 2, sf::Lines);
		window.draw(part5, 2, sf::Lines);
		window.draw(arc1);
	}

	void Figure::_drawAllParts(sf::RenderWindow &window) {
		const float angle = pi / 2;
		const float start_angle = _angle;

		for (int i = 0; i < 4; i++) {
			_setPoints();
			_drawPart(window);
			setAngle(_angle + angle);
		}


		setAngle(start_angle);
	}

	void Figure::draw(sf::RenderWindow &window) {
		sf::CircleShape circle(_radius);
		circle.setOrigin(_radius, _radius);
		circle.setPosition(_center);
		circle.setFillColor(sf::Color::Transparent);
		circle.setOutlineThickness(1);
		window.draw(circle);

		_drawAllParts(window);

	}

	sf::VertexArray Figure::_getBezier(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, int number) {
		sf::VertexArray arc(sf::LineStrip, number);

		for (int i = 0; i < number; i++) {
			float t = i / float(number - 1);
			arc[i].position = ((1.f - t) * (1.f - t)) * p1 + (2.f * (1.f - t) * t) * p2 + (t * t) * p3;
		}
		return arc;
	}
}
