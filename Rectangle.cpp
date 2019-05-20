#include "Rectangle.h"



Rectangle::Rectangle(sf::Vector2f point1, sf::Vector2f point2) : vertex(sf::LineStrip, 4)
{
	vertex[0].position = point1;
	vertex[1].position = {point1.x, point2.y};
	vertex[2].position = point2;
	vertex[3].position = {point2.x, point1.y};
}


Rectangle::~Rectangle()
{
}

void Rectangle::draw(sf::RenderWindow & window)
{
	sf::VertexArray draw_vertex = vertex;
	draw_vertex.append(vertex[0]);
	window.draw(draw_vertex);
}

void Rectangle::move(float x, float y)
{
	for (int i = 0; i < 4; ++i) {
		vertex[i].position += {x, y};
	}
}

void Rectangle::rotate_around_point(float angle, float x, float y)
{
	sf::Vector2f rotate_center(x, y);
	for (int i = 0; i < 4; ++i) {
		sf::Vector2f diff = vertex[i].position - rotate_center;
		vertex[i].position = rotate_center + rotate_point(angle, diff);
	}
}

void Rectangle::scale_around_point(float scale, float x, float y)
{
	sf::Vector2f scaled_center(x, y);
	for (int i = 0; i < 4; ++i) {
		sf::Vector2f diff = vertex[i].position - scaled_center;
		vertex[i].position = scaled_center + diff * scale;
	}
}

void Rectangle::rotate(float angle){
	sf::Vector2f rotate_center = (vertex[0].position + vertex[2].position)/2;
	rotate_around_point(angle, rotate_center.x, rotate_center.y);
}