#pragma once

#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace snow {

	class Snowflake {
	public:
		Snowflake();
		Snowflake(sf::Vector2f coords, float angle = 0, float size = 20);
		void draw(sf::RenderWindow &window);
		void setPosition(sf::Vector2f coords);
		sf::Vector2f getPosition();
		void move(sf::Vector2f offset);
		void setAngle(float angle);
		float getAngle();
		void rotate(float angle);
		~Snowflake() {};

	private:
		void drawFragment(sf::RenderWindow &window, float fragmentAngle);

		float _size;
		sf::Vector2f _coords;
		float _angle;

		// ”гол создаваемый точками p2, p0, p6
		static const double _BETA1;

		// ”гол создаваемый точками p6, p0, p5
		static const double _BETA2;

		// ƒлина отрезка p0p2
		static const double _P0P2;

		// ƒлина отрезка p0p8
		static const double _P0P8;
	};

} //namespace snow

