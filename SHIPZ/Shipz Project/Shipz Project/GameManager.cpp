#include "GameManager.h"



GameManager::GameManager()
{
	myUnit = Unit();

	unitTextures.loadFromFile("../Textures/LittleBro.png");

	myUnit.Init(&unitTextures);
}


GameManager::~GameManager()
{
}

void GameManager::GameLoop(float deltaTime)
{
	myUnit.UpdateLoop(deltaTime);
}

void GameManager::RenderGame(sf::RenderWindow * window)
{
	window->draw(myUnit.shape);
}
