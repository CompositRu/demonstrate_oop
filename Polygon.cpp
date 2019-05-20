#include "Polygon.h"

#include <cmath>
#include <stdexcept>

const float  PI_F = 3.14159265358979f;

Polygon::Polygon(sf::Vector2f center, float radius, unsigned int amount_points) : vertex(sf::LineStrip, amount_points)
{
	float angle = PI_F / amount_points;
	for (int i = 0; i < amount_points; ++i_{
		float x = cos(angle * i) * radius;
		float y = sin(angle * i) * radius;
		vertex[i].position = center + sf::Vector2f(x, y);
	}
}

Polygon::~Polygon()
{
}

void Polygon::draw(sf::RenderWindow& window)
{
	sf::VertexArray draw_vertex = vertex;
	draw_vertex.append(vertex[0]);
	window.draw(draw_vertex);
}



