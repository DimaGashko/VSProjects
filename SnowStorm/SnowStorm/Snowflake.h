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

		static const double _BETA1;
		static const double _BETA2;
		static const double _D02;
		static const double _D08;
	};

} //namespace snow

