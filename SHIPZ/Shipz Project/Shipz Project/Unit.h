#pragma once
#include <SFML\Graphics.hpp>

class Unit
{
public:
	Unit();
	~Unit();

	void Init(sf::Texture * text);

	void UpdateLoop(float deltaTime);

	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Texture * texture;

private:
	float m_width;
	float m_height;

	float m_movemeantSpeed;

	sf::Vector2f m_lastPos;
};

