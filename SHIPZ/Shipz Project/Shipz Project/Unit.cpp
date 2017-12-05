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

	texture = text;

	m_width = (float)texture->getSize().x;
	m_height = (float)texture->getSize().y;

	shape = sf::RectangleShape(sf::Vector2f(m_width, m_height));
	shape.setTexture(texture);
	shape.setOrigin(m_width - (m_width * 0.05f), m_height - (m_height * 0.5f));
	

}

void Unit::UpdateLoop(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= m_movemeantSpeed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += m_movemeantSpeed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		position.y -= m_movemeantSpeed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		position.y += m_movemeantSpeed * deltaTime;
	}

	if (m_lastPos != position)
	{
		shape.setPosition(position);
		m_lastPos = position;
	}
}
