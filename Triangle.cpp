#include "Triangle.h"

#include <iostream>
#include <iomanip>


Triangle::Triangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3) : vertex(sf::LineStrip, 3)
{
	vertex[0].position = point1;
	vertex[1].position = point2;
	vertex[2].position = point3;
}


Triangle::~Triangle()
{
}

void Triangle::draw(sf::RenderWindow& window)
{
	sf::VertexArray draw_vertex = vertex;
	draw_vertex.append(vertex[0]);
	window.draw(draw_vertex);
}

void Triangle::move(float x, float y)
{
	for (int i = 0; i < 3; ++i) {
		vertex[i].position += {x, y};
	}
}

void Triangle::rotate_around_point(float angle, float x, float y)
{
	sf::Vector2f rotate_center(x, y);
	for (int i = 0; i < 3; ++i) {
		sf::Vector2f diff = vertex[i].position - rotate_center;
		vertex[i].position = rotate_center + rotate_point(angle, diff);
	}		
}

void Triangle::scale_around_point(float scale, float x, float y)
{
	sf::Vector2f scaled_center(x, y);
	for (int i = 0; i < 3; ++i) {
		sf::Vector2f diff = vertex[i].position - scaled_center;
		vertex[i].position = scaled_center + diff * scale;
	}
}

void Triangle::print() const
{
	bool flag = false;
	for (int i = 0; i < 3; ++i) {
		if (flag) std::cout << ", ";
		flag = true;
		std::cout << std::setprecision(2);
		std::cout << "{" << vertex[i].position.x << ", "
			<< vertex[i].position.y << "}";
	}
	std::cout << std::endl;
}

