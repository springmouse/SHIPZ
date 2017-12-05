#pragma once
#include <SFML\Graphics.hpp>
#include "Unit.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void GameLoop(float deltaTime);
	void RenderGame(sf::RenderWindow * window);

	sf::Texture unitTextures;

	Unit myUnit;
};

