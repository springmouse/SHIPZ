#include "SFMLRenderClass.h"
#include <iostream>



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
		m_time = m_deltaTime.restart();

		if (ScreenEvents() == false)
		{
			return false;
		}

		gm.GameLoop(m_time.asSeconds());

		RenderLoop();
	}
}

bool SFMLRenderClass::ScreenEvents()
{
	window->pollEvent(m_event);


	switch (m_event.type)
	{
		case sf::Event::Closed:
			return false;

		case sf::Event::LostFocus:
			return true;

		case sf::Event::GainedFocus:
			return true;

		case sf::Event::TextEntered:
			return true;

		case sf::Event::KeyPressed:
			return true;

		case sf::Event::KeyReleased:
			return true;

		case sf::Event::MouseButtonPressed:
			return true;

		case sf::Event::MouseButtonReleased:
			return true;

		case sf::Event::MouseMoved:
			return true;

		case sf::Event::MouseLeft:
			return true;

		case sf::Event::MouseEntered:
			return true;
	}



	std::cout << "Event " << m_event.type << " Had No Switch StatMeant: SFMLRenderClass, ScreenEvents()" << std::endl;
	return true;
}

void SFMLRenderClass::RenderLoop()
{

	window->clear();

	gm.RenderGame(window);

	window->display();
}
