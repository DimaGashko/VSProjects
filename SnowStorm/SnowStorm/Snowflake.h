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
		void updateConfig(float a);

		float _size;
		sf::Vector2f _coords;
		float _angle;

		sf::Vector2f _p1 = sf::Vector2f(0, 0);
		sf::Vector2f _p2 = sf::Vector2f(0, 0);
		sf::Vector2f _p3 = sf::Vector2f(0, 0);
		sf::Vector2f _p4 = sf::Vector2f(0, 0);
		sf::Vector2f _p5 = sf::Vector2f(0, 0);
		sf::Vector2f _p6 = sf::Vector2f(0, 0);
		sf::Vector2f _p7 = sf::Vector2f(0, 0);
		sf::Vector2f _p8 = sf::Vector2f(0, 0);
		sf::Vector2f _p9 = sf::Vector2f(0, 0);


		static const double _angleB1;
		static const double _angleB2;
		static const double _d02;
		static const double _d08;
	};

} //namespace snow