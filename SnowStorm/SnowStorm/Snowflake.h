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

		static const double _BETA1;
		static const double _BETA2;
		static const double _D02;
		static const double _D08;
	};

} //namespace snow

