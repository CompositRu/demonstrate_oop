#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <random>  
#include <ctime> 

#include "Triangle.h"
#include "Rectangle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "oop");
	
	std::mt19937 gen(time(0)); 
	std::uniform_real_distribution<> urd_coord(10, 50);
	std::uniform_real_distribution<> urd_angle(0.5, 1.5);
	std::uniform_real_distribution<> urd_scale(0, 1);
	
	Triangle triangle({10, 10}, {10, 50}, {50, 10});
	Triangle triangle2 = triangle;
	triangle2.scale_around_point(3 * urd_scale(gen), 0, 0);
	triangle2.move(30, 10);
	triangle2.rotate_around_point(urd_angle(gen), 100, 100);
	
	Rectangle rect({100, 100}, {200, 150 });
	Rectangle rect2 = rect;
	rect2.scale_around_point(urd_angle(gen), 110, 110);
	rect2.move(urd_coord(gen), urd_coord(gen));
	rect2.rotate_around_point(urd_angle(gen), 100, 100);
	
	Polygon circle({100, 100}, 50, 100);
	
	std::vector<std::shared_ptr<drawable>> draw_vector;
	draw_vector.push_back(std::make_shared<drawable>(triangle));
	draw_vector.push_back(std::make_shared<drawable>(triangle2));
	draw_vector.push_back(std::make_shared<drawable>(rect));
	draw_vector.push_back(std::make_shared<drawable>(rect2));
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (const auto& draw_obj : draw_vector){
			draw_obj.draw(window);
		}
		window.display();
	}

	return 0;
}