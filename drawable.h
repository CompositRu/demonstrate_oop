#pragma once
#include <SFML/Graphics.hpp>

class drawable
{
public:
	drawable();
	virtual ~drawable();

	virtual void draw(sf::RenderWindow& window) = 0;
};

