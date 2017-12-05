#pragma once
#include <SFML\Graphics.hpp>
#include<memory>

class SFMLRenderClass
{
public:
	SFMLRenderClass();
	~SFMLRenderClass();

	sf::RenderWindow * window;

	bool UpdateLoop();
	void RenderLoop();

private:
	sf::Event m_event;
};

