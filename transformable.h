#pragma once
#include <SFML/Graphics.hpp>

class transformable
{
public:
	transformable();
	virtual ~transformable();

	virtual void move(float x, float y) = 0;
	virtual void rotate_around_point(float angle, float x, float y) = 0;
	virtual void scale_around_point (float scale, float x, float y) = 0;
};

sf::Vector2f rotate_point(float angle, sf::Vector2f point);