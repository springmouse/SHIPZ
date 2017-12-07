#pragma once
#include <SFML\Graphics.hpp>

#define VECTORMATHS VectorMaths::GetInstanceOfVectorMaths() /*lets us call and use the factory*/

class VectorMaths
{
public:

	static VectorMaths * GetInstanceOfVectorMaths();

	float Vector2fDotProduct(sf::Vector2f vecA, sf::Vector2f vecB);

	float Vector2fSquaredMagnatude(sf::Vector2f vecA);
	float Vector2fSquareRootMagnatude(sf::Vector2f vecA);

	sf::Vector2f NormalizVector2f(sf::Vector2f vecA);

private:
	VectorMaths() {}

	~VectorMaths() {}

};

