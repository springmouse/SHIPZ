#pragma once
#include <SFML\Graphics.hpp>
#include<memory>
#include "GameManager.h"

class SFMLRenderClass
{
public:
	SFMLRenderClass();
	~SFMLRenderClass();

	sf::RenderWindow * window;

	GameManager gm;

	bool UpdateLoop();
	void RenderLoop();

private:
	sf::Event m_event;

	bool ScreenEvents();

	sf::Clock m_deltaTime;

	sf::Time m_time;
};

