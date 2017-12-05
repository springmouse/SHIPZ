#include "SFMLRenderClass.h"



SFMLRenderClass::SFMLRenderClass()
{
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "SHIPZ", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
}


SFMLRenderClass::~SFMLRenderClass()
{
}

bool SFMLRenderClass::UpdateLoop()
{
	while (true)
	{
		if (window->pollEvent(m_event))
		{
			if (m_event.type == m_event.Closed)
			{
				return false;
			}
		}

		RenderLoop();
	}
}

void SFMLRenderClass::RenderLoop()
{

	window->clear();

	//Darw to window

	window->display();
}
