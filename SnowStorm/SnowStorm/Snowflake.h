#pragma once

#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace snow {

	class Snowflake {
	public:
		Snowflake();
		void draw(sf::RenderWindow &window);
		//void setPosition();
		//void getPosition();
		//void move();
		//void setAngle();
		//void getAngle();
		//void rotate();
		~Snowflake() {};

	private:
		void drawFragment(sf::RenderWindow &window, float fragmentAngle);

		float _size;
		sf::Vector2f _coords;
		float _angle;

		static const double _angleB1;
		static const double _angleB2;
		static const double _d02;
		static const double _d08;
	};

} //namespace snow