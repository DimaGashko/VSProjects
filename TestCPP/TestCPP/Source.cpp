#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

using namespace std;
using namespace sf;

float PI = 3.1415926535;
RenderWindow window;

class figure
{
private:
	Vector2f x0;
	float r;
	float al;

	void Figure(Vector2f x0, float r, float al) {
		point_arr(x0, r, al - PI);
		point_arr(x0, r, al - PI / 2);
		point_arr(x0, r, al - PI * 2);
		point_arr(x0, r, al - PI - PI / 2);
	}

	void point_arr(Vector2f x0, float r, float al) {
		Vector2f point[9];
		float temp;
		point[0] = f_point(x0, 8 * r, al + rad(90));

		temp = acos(1 / sqrt(37));
		point[1] = f_point(x0, sqrt(37) * r, al + temp);

		point[2] = f_point(x0, 4 * r, al + rad(90));

		temp = rad(90);
		point[3] = f_point(x0, 6 * r, al + temp);

		temp = 0;
		point[4] = f_point(x0, 8 * r, al + temp);

		temp = acos(6 / sqrt(37));
		point[5] = f_point(x0, sqrt(37) * r, al + temp);

		temp = 0;
		point[6] = f_point(x0, 4 * r, al + temp);

		temp = 0;
		point[7] = f_point(x0, 6 * r, al + temp);

		temp = acos(4 / sqrt(32));
		point[8] = f_point(x0, sqrt(32) * r, al + temp);
		print_point(point, x0, r, al);
	}

	void print_point(Vector2f a[9], Vector2f x0, float r, float al) {
		VertexArray lines(Lines, 2);

		lines[0].position = a[0];
		lines[1].position = a[1];
		window.draw(lines);

		lines[0].position = a[1];
		lines[1].position = a[2];
		window.draw(lines);

		lines[0].position = a[3];
		lines[1].position = x0;
		window.draw(lines);

		lines[0].position = a[3];
		lines[1].position = a[7];
		window.draw(lines);

		lines[0].position = a[5];
		lines[1].position = a[6];
		window.draw(lines);

		lines[0].position = a[5];
		lines[1].position = a[4];
		window.draw(lines);

		lines[0].position = a[7];
		lines[1].position = x0;
		window.draw(lines);

		int step = 1;

		for (int i = 90; i > 0; i -= step) {
			lines[0].position = f_point(x0, 2 * r, al + rad(i));
			i -= step;
			lines[1].position = f_point(x0, 2 * r, al + rad(i));
			i += step;
			window.draw(lines);
		}

		for (int i = 360; i > 270; i -= step) {
			lines[0].position = f_point(a[2], 4 * r, al + rad(i));
			i -= step;
			lines[1].position = f_point(a[2], 4 * r, al + rad(i));
			i += step;
			window.draw(lines);
		}

		for (int i = 180; i > 90; i -= step) {
			lines[0].position = f_point(a[6], 4 * r, al + rad(i));
			i -= step;
			lines[1].position = f_point(a[6], 4 * r, al + rad(i));
			i += step;
			window.draw(lines);
		}
	}

	float rad(float a) {
		return a * PI / 180;
	}


	Vector2f f_point(Vector2f x0, float r, float fi) {

		Vector2f a;
		a.x = x0.x + r * cos(fi);
		a.y = x0.y + r * sin(fi);

		return a;
	}

public:
	void set_pos(Vector2f x0_, float r_, float al_) {
		x0 = x0_;
		r = r_;
		al = al_;
	}

	void print() {
		Figure(x0, r, al);
	}

	figure() {
		x0 = Vector2f(500, 500);
		r = 25;
		al = 0;
	}
};

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(VideoMode(1280, 720), "SFMLworks", Style::Default, settings);

	figure f1;
	Vector2f x0;
	float r = 25;
	float al = 0;
	x0 = Vector2f(500, 300);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (Keyboard::isKeyPressed(Keyboard::Up)) r += 1;
		if (Keyboard::isKeyPressed(Keyboard::Down)) if (r > 0) r -= 1;
		if (Keyboard::isKeyPressed(Keyboard::D)) x0.x += 5;
		if (Keyboard::isKeyPressed(Keyboard::A)) x0.x -= 5;
		if (Keyboard::isKeyPressed(Keyboard::S)) x0.y += 5;
		if (Keyboard::isKeyPressed(Keyboard::W)) x0.y -= 5;
		if (Keyboard::isKeyPressed(Keyboard::Left)) al -= 0.01;
		if (Keyboard::isKeyPressed(Keyboard::Right)) al += 0.01;

		f1.set_pos(x0, r, al);

		window.clear();
		f1.print();
		window.display();
	}

	return 0;
}


