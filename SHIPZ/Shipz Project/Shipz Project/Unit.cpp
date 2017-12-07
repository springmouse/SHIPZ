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

	m_buttonUse = false;

	theWindow = nullptr;

	m_rotation = 0;
}

void Unit::UpdateLoop(float deltaTime)
{
	timer += deltaTime;

	if (m_buttonUse)
	{
		ButtonUpdate(deltaTime);
	}
	else
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (theWindow != nullptr && timer > 1)
			{
				moveTarget = (sf::Vector2f)sf::Mouse::getPosition(*theWindow);

				CalculatRotation();

				printf("%f | %f | rotation = %f \n", moveTarget.x, moveTarget.y, m_rotation);

				timer = 0;
			}
		}

		if (moveTarget != position)
		{
			position += (VECTORMATHS->NormalizVector2f(moveTarget - position) * m_movemeantSpeed) * deltaTime;
		}
	}

	m_anim.Update(deltaTime);
}

void Unit::CalculatRotation()
{
	if (m_rotation != m_rotation)
	{
		m_rotation = 0;
	}

	float dotProduct = VECTORMATHS->Vector2fDotProduct(position, (moveTarget - position));
	float magA = VECTORMATHS->Vector2fSquareRootMagnatude(position);
	float magB = VECTORMATHS->Vector2fSquareRootMagnatude((moveTarget - position));

	m_rotation += acos(dotProduct / (magA * magB)) * 180.0f / 3.14f;
}

void Unit::ButtonUpdate(float deltaTime)
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
}

void Unit::RenderLoop(sf::RenderWindow * window)
{
	theWindow = window;

	if (m_buttonUse)
	{
		ButtonMoveRender(window);
	}
	else
	{
		m_anim.RenderLoop(0, window, position, m_rotation);
	}
}

void Unit::ButtonMoveRender(sf::RenderWindow * window)
{
	////////////////////////////////////////////////////////

	if (m_lastPos == position)
	{
		m_anim.RenderLoop(0, window, position, true, true);
	}

	if (m_yMovemeant == -1)
	{
		m_anim.RenderLoop(1, window, position, true, true);
	}

	if (m_yMovemeant == 1)
	{
		m_anim.RenderLoop(1, window, position, true, false);
	}

	if (m_xMovemeant == 1)
	{
		if (m_yMovemeant == 1)
		{
			m_anim.RenderLoop(2, window, position, true, false);
		}
		else
		{
			m_anim.RenderLoop(2, window, position, true, true);
		}
	}

	if (m_xMovemeant == -1)
	{
		if (m_yMovemeant == 1)
		{
			m_anim.RenderLoop(2, window, position, false, false);
		}
		else
		{
			m_anim.RenderLoop(2, window, position, false, true);
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

