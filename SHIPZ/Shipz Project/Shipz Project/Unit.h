#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"

class Unit
{
public:
	Unit();
	~Unit();

	void Init(sf::Texture * text);

	void UpdateLoop(float deltaTime);
	void RenderLoop(sf::RenderWindow * window);

	sf::Vector2f position;
	
private:

	int m_xMovemeant;
	int m_yMovemeant;

	int kill;

	float m_movemeantSpeed;

	sf::Vector2f m_lastPos;

	Animation m_anim;
};

