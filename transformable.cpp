#include "transformable.h"

#include <cmath>

transformable::transformable()
{
}


transformable::~transformable()
{
}

sf::Vector2f rotate_point(float angle, sf::Vector2f point) {
	sf::Vector2f result;
	result.x = cos(angle) * point.x - sin(angle) * point.y;
	result.y = sin(angle) * point.x + cos(angle) * point.y;
	return result;
}