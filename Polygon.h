#pragma once
#include "drawable.h"

#include <SFML/Graphics.hpp>


class Polygon :
	public drawable,
{
public:
	Polygon(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3);
	~Polygon();

	void draw(sf::RenderWindow& window) override;

private:
	sf::VertexArray vertex;
};
