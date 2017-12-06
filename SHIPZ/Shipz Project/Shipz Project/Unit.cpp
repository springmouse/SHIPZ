#include "Unit.h"



Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::Init(sf::Texture * text)
{
	m_movemeantSpeed = 100;

	position = sf::Vector2f(0, 0);

	m_anim = Animation(text, sf::Vector2u(3,4), 0.33f);
}

void Unit::UpdateLoop(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= m_movemeantSpeed * deltaTime;
		m_xMovemeant = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += m_movemeantSpeed * deltaTime;
		m_xMovemeant = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		position.y -= m_movemeantSpeed * deltaTime;
		m_yMovemeant = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		position.y += m_movemeantSpeed * deltaTime;
		m_yMovemeant = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		kill = 1;
	}

	m_anim.Update(deltaTime);
}

void Unit::RenderLoop(sf::RenderWindow * window)
{
	////////////////////////////////////////////////////////
	
	if (kill == 1)
	{
		m_anim.RenderLoop(3, window, position);
	}
	else
	{
		if (m_lastPos == position)
		{
			m_anim.RenderLoop(0, window, position);
		}

		if (m_yMovemeant == -1)
		{
			m_anim.RenderLoop(1, window, position);
		}

		if (m_xMovemeant == 1)
		{
			m_anim.RenderLoop(2, window, position);
		}
	}
	
	////////////////////////////////////////////////////////

	if (m_lastPos != position)
	{
		m_lastPos = position;
	}

	if (m_xMovemeant != 0)
	{
		m_xMovemeant = 0;
	}

	if (m_yMovemeant != 0)
	{
		m_yMovemeant = 0;
	}

	if (kill == 1)
	{
		kill = 0;
	}

	////////////////////////////////////////////////////////
}
