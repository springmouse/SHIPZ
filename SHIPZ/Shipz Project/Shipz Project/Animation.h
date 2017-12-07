#pragma once
#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation();
	Animation(sf::Texture * text, sf::Vector2u imagecount, float animTime);
	~Animation();

	void Update(float deltaTime);
	void RenderLoop(int row, sf::RenderWindow * window, sf::Vector2f pos, float rotation);
	void RenderLoop(int row, sf::RenderWindow * window, sf::Vector2f pos, bool faceRight, bool faceUp);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currImage;

	float timer;
	float switchTime;

	sf::Texture * m_texture;
	sf::RectangleShape m_shape;
};

