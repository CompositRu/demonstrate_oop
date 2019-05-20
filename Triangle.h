#pragma once
#include "drawable.h"
#include "transformable.h"

#include <SFML/Graphics.hpp>


class Triangle :
	public drawable,
	public transformable
{
public:
	Triangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3);
	~Triangle();

	void draw(sf::RenderWindow& window) override;
	void move(float x, float y) override;
	void rotate_around_point(float angle, float x, float y) override;
	void scale_around_point(float scale, float x, float y) override;

	void print() const;
private:
	sf::VertexArray vertex;
};
