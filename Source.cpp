#include <SFML/Graphics.hpp>
#include <iostream>

#include "Triangle.h"
#include "Rectangle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "oop");

	Triangle triangle({10, 10}, {10, 50}, {50, 10});
	Triangle triangle2 = triangle;
	triangle2.scale_around_point(3, 0, 0);
	triangle2.move(30, 10);
	triangle2.rotate_around_point(1, 100, 100);
	Rectangle rect({100, 100}, {200, 150 });
	Rectangle rect2 = rect;
	rect2.scale_around_point(0.7, 110, 110);
	rect2.move(30, 10);
	rect2.rotate_around_point(1, 100, 100);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		triangle.draw(window);
		triangle2.draw(window);
		rect.draw(window);
		rect2.draw(window);
		window.display();
	}

	return 0;
}