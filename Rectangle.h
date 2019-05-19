#pragma once
#include "drawable.h"
#include "transformable.h"

class Rectangle :
	public drawable,
	public transformable
{
public:
	Rectangle(sf::Vector2f point1, sf::Vector2f point2);
	~Rectangle();

	void draw(sf::RenderWindow& window) override;
	void move(float x, float y) override;
	void rotate_around_point(float angle, float x, float y) override;
	void scale_around_point(float scale, float x, float y) override;

private:
	sf::VertexArray vertex;
};

