#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "VectorMaths.h"

class Unit
{
public:
	Unit();
	~Unit();

	void Init(sf::Texture * text);

	void UpdateLoop(float deltaTime);
	void RenderLoop(sf::RenderWindow * window);

	void ButtonUpdate(float deltaTime);
	void ButtonMoveRender(sf::RenderWindow * window);

	void CalculatRotation();

	sf::RenderWindow * theWindow;

	sf::Vector2f position;
	sf::Vector2f moveTarget;

private:
	float timer = 0;

	bool m_buttonUse;

	int m_xMovemeant;
	int m_yMovemeant;

	int kill;

	float m_movemeantSpeed;

	float m_rotation;

	sf::Vector2f m_lastPos;

	Animation m_anim;
};

