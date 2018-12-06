
#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <SFML\Graphics.hpp>

namespace figure {

	class Figure {
	public:
		Figure();
		Figure(float angle, float radius, sf::Vector2f center);
		~Figure() {};
		void setRadius(float radius);
		float getRadius();
		void setAngle(float angle);
		float getAngle();
		sf::Vector2f getCenter();
		void setCenter(sf::Vector2f v);
		void rotate(float direction = -1.f);
		void scale(float coeficient = 1.f);
		void draw(sf::RenderWindow &window);
		void move(float x, float y);

	private:
		sf::Vector2f _center;
		float _angle;
		float _radius;
		const double _alpha = atan(1.f / 5.f);
		const double _sigma = atan(1.f / 2.f);
		const double _a = sqrt(26) / 4;
		void _drawPart(sf::RenderWindow &window);
		void _drawAllParts(sf::RenderWindow &window);
		void _setPoints();
		sf::VertexArray _getBezier(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, int number = 50);
		sf::Vector2f _p1, _p2, _p3, _p4, _p5, _p6, _p7, _p8, _p9, _p10, _p11, _p12, _p13;

	};

}

#endif
