#include "VectorMaths.h"


VectorMaths * VectorMaths::GetInstanceOfVectorMaths()
{
	static VectorMaths vectorMaths;

	return &vectorMaths;
}

float VectorMaths::Vector2fDotProduct(sf::Vector2f vecA, sf::Vector2f vecB)
{
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);
}

float VectorMaths::Vector2fSquaredMagnatude(sf::Vector2f vecA)
{
	return (vecA.x * vecA.x) + (vecA.y * vecA.y);
}

float VectorMaths::Vector2fSquareRootMagnatude(sf::Vector2f vecA)
{
	float squaredMag = (vecA.x * vecA.x) + (vecA.y * vecA.y);
	squaredMag = sqrt(squaredMag);
	return squaredMag;
}

sf::Vector2f VectorMaths::NormalizVector2f(sf::Vector2f vecA)
{
	float magnatude = Vector2fSquareRootMagnatude(vecA);

	return vecA / magnatude;
}
