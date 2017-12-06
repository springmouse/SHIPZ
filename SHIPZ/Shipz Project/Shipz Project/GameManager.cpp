#include "GameManager.h"



GameManager::GameManager()
{
	myUnit = Unit();

	unitTextures.loadFromFile("../Textures/Fighter Sprites.png");

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
	myUnit.RenderLoop(window);
}
